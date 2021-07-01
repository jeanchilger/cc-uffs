import argparse
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from models import Model
from activations import Sigmoid

parser = argparse.ArgumentParser()

args = parser.parse_args()

if __name__ == "__main__":
    # Data loading
    raw_dataset = pd.read_csv("arruela_dataset.csv")

    labels = ["Output1", "Output2"]

    X = raw_dataset.drop(labels, axis=1)
    y = raw_dataset[labels]

    X_train, X_test, y_train, y_test = train_test_split(X, y)