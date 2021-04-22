import argparse
import queue
import re
import utils.regex_parser as rp
from utils.database import DBManager

started_transactions = queue.Queue()
commited_transactions = set()
checkpoint_started = queue.Queue()
checkpoint_finished = set()

redo_values = {}
database_copy = {}

parser = argparse.ArgumentParser()

parser.add_argument(
        "-l", "--log-file", help="Path to the log file",
        dest="log_file")

if __name__ == "__main__":
    args = parser.parse_args()
    log_file_path = args.log_file
    first_line = True
    db = DBManager()

    with open(log_file_path, "r") as log_file:
        for line in log_file:
            if first_line:
                first_line = False

                line_list = line.split("|")
                columns = [item.split("=")[0].strip() for item in line_list]
                values = [item.split("=")[1].strip() for item in line_list]

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
                started_transactions.put(start_t.upper())
            
            elif commit_t is not None:
                commited_transactions.add(commit_t.upper())

            # elif checkpoint_t is not None:
            #     for t in commited_transactions:
            #         # print(t)
            #         checkpoint_started.put(t.upper())
            #     # exit()

            elif rp.is_checkpoint_end(line):
                for t in commited_transactions:
                    # print(t)
                    checkpoint_finished.add(t)

                    # checkpoint_started.put(t.upper())
                # while not checkpoint_started.empty():
                #     t = checkpoint_started.get()
                #     checkpoint_finished.add(t)

            else:
                _values = rp.get_values(line)
                redo_values[_values[0]] = _values[1:]

    # Get all commited transactions that doesn't 
    # occur in any checkpoint
    while not len(commited_transactions) == 0:
        t = commited_transactions.pop()
        if t not in checkpoint_finished:
            print("{} realizou REDO.".format(t))

            pk, column, value = redo_values[t]
            if pk in database_copy:
                database_copy[pk] = {**database_copy[pk], column: value}
            else:
                database_copy[pk] = {column: value}

    for t in checkpoint_finished:
        print("{} não realizou REDO.".format(t))


    # print(database_copy)

    for pk in database_copy:
        db.update(
                list(database_copy[pk].values()),
                list(database_copy[pk].keys()), pk)