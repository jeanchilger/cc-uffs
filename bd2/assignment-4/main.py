import argparse
import queue
import re
import utils.regex_parser as rp
from utils.database import DBManager

started_transactions = set()
commited_transactions = set()
checkpoint_started = queue.Queue()
checkpoint_finished = set()

redo_values = {}
database_copy = {}

parser = argparse.ArgumentParser()

parser.add_argument(
        "-l", "--log-file", help="Path to the log file",
        dest="log_file")


def format_entry(string, modified_columns=None):
    if modified_columns is not None and string in modified_columns:
        return "\033[1;91m" + string.ljust(3).rjust(6) + "\033[0m"

    else:
        return string.ljust(3).rjust(6)


if __name__ == "__main__":
    args = parser.parse_args()
    log_file_path = args.log_file
    first_line = True
    columns = []
    initial_state = {}
    db = DBManager()

    with open(log_file_path, "r") as log_file:
        for line in log_file:
            if first_line:
                first_line = False

                line_list = line.split("|")
                columns = [item.split("=")[0].strip() for item in line_list]
                values = [item.split("=")[1].strip() for item in line_list]

                for column, value in zip(columns, values):
                    initial_state[column] = value

                db.drop_table()
                db.create_table(columns=columns)
                db.insert(values=tuple(values), columns=tuple(columns))

                continue

            # Transaction start detection
            start_t = rp.get_transaction_start(line)
            # Commited transaction detection
            # These transaction are candidates to REDO
            commit_t = rp.get_transaction_commit(line)

            checkpoint_t = rp.get_checkpoint_start(line)

            if start_t is not None:
                started_transactions.add(start_t.upper())
            
            elif commit_t is not None:
                commited_transactions.add(commit_t.upper())
                started_transactions.remove(commit_t.upper())

            elif rp.is_checkpoint_end(line):
                for t in commited_transactions:
                    checkpoint_finished.add(t)

            else:
                _values = rp.get_values(line)
                redo_values[_values[0]] = _values[1:]

    # Get all commited transactions that doesn't 
    # occur in any checkpoint
    while not len(commited_transactions) == 0:
        t = commited_transactions.pop()
        if t not in checkpoint_finished:
            print("Transaction \033[1;97m{}\033[0m performed REDO.".format(t))

            pk, column, value = redo_values[t]
            if pk in database_copy:
                database_copy[pk] = {**database_copy[pk], column: value}
            else:
                database_copy[pk] = {column: value}

    print()
    for t in checkpoint_finished:
        print("Transaction \033[1;97m{}\033[0m DID NOT performed REDO.".format(t))


    for t in  started_transactions:
        print("Transaction \033[1;97m{}\033[0m is corrupted (i.e. started but not commited).".format(t))

    # Setup final table values to be printed
    modified_columns = []
    for pk in database_copy:
        for column, value in database_copy[pk].items():
            if initial_state[column] != value:
                modified_columns.append(column)
                db.update([value], list(column), pk)

    _columns = [
            format_entry(column_name, modified_columns)
            for column_name in columns]
    _values = [
            format_entry(str(value)) 
            for value in db.select(columns=tuple(columns))]

    print("|".join(_columns))
    print("|".join(_values))