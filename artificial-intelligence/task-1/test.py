import argparse
from pprint import pprint
from layers.dense import Dense
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from models import Model
from layers import Layer
from activations import Sigmoid, TanH, ReLU
from losses import MSE, CrossEntropy
from metrics.classification import accuracy

parser = argparse.ArgumentParser()

parser.add_argument(
        "-e", "--epochs", help="Training epochs.",
        dest="epochs", type=int, default=1000)

parser.add_argument(
        "-l", "--learn-rate", help="Training epochs.",
        dest="learn_rate", type=float, default=0.5)

args = parser.parse_args()


if __name__ == "__main__":
    epochs = args.epochs
    learn_rate = args.learn_rate
    
    # Data loading
    raw_dataset = pd.read_csv("arruela_dataset.csv")

    labels = ["Output1"]
    features = ["NumAmostra", "Area", "Delta"]

    scaler = StandardScaler()
    dataset = scaler.fit_transform(raw_dataset[[*labels, *features]])
    dataset = pd.DataFrame(dataset, columns=[*labels, *features])

    print(dataset.head())

    X = dataset[features].to_numpy()
    y = dataset[labels].to_numpy()
    

    X_train, X_test, y_train, y_test = train_test_split(
            X, y, test_size=.3, random_state=0)
    
    # Model creation
#     
