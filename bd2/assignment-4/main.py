import argparse
from utils.database import DBManager

# dbm = DBManager()

# id = dbm.insert((1, 2, 3, 4))

# dbm.update((5, 6), ("A", "B"), id)


parser = argparse.ArgumentParser()

parser.add_argument(
        "-l", "--log-file", help="Path to the log file",
        dest="log_file")

if __name__ == "__main__":
    args = parser.parse_arguments()
    log_file_path = args.log_file

    with open(log_file_path, "r") as log_file:
        for line in log_file:
            print(line)