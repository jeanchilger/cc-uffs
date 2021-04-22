import re


def get_transaction_start(string):
    """
    Returns the transaction being started at 'string' or
    None if no transaction start was detected.

    Args:
        string (str):

    Returns:
        str: The transaction that started. Returns None
            if the given string isn't a transaction start.
    """

    if re.search("start", string, re.IGNORECASE):
        output = re.search("(?<=<)(.*)(?=>)", string, re.IGNORECASE)

        # If the first string after "start" is T[0-9]
        if re.fullmatch("T[0-9]", output.group(0).split(" ")[1], re.IGNORECASE):
            return output.group(0).split(" ")[1]

    return None


def get_transaction_commit(string):
    if re.search("commit", string, re.IGNORECASE):
        output = re.search("(?<=<)(.*)(?=>)", string, re.IGNORECASE)

        # If the first string after "start" is T[0-9]
        if re.fullmatch("T[0-9]", output.group(0).split(" ")[1], re.IGNORECASE):
            return output.group(0).split(" ")[1]

    return None


def get_checkpoint_start(string):
    if re.search("Start CKPT", string, re.IGNORECASE):
        output = re.search("(?<=\()(.*)(?=\))", string, re.IGNORECASE)

        valid_output = []
        for t in output.group(0).split(","):
            if re.fullmatch("T[0-9]", t.strip(), re.IGNORECASE):
                valid_output.append(t.strip())

        return valid_output

    return None


def is_checkpoint_end(string):
    if re.search("End CKPT", string, re.IGNORECASE):
        return True
    
    return False


def get_values(string):
    output = re.search("(?<=<)(.*)(?=>)", string, re.IGNORECASE)
    
    log_values = []
    for val in output.group(0).split(","):
        log_values.append(val.strip())

    return log_values
