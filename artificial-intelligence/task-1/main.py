import argparse
from pprint import pprint
import activations
from layers import Dense
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from models import Model
from layers import Layer, layer
from activations import Sigmoid, TanH, ReLU
from losses import MSE, CrossEntropy
from metrics.classification import accuracy
from utils import graphics

parser = argparse.ArgumentParser()

parser.add_argument(
        "-e", "--epochs", help="Training epochs.",
        dest="epochs", type=int, default=1000)

parser.add_argument(
        "-l", "--learning-rate", help="Learning rate.",
        dest="learning_rate", type=float, default=0.5)

args = parser.parse_args()


if __name__ == "__main__":
    epochs = args.epochs
    learning_rate = args.learning_rate

    # Data loading
    raw_dataset = pd.read_csv("arruela_dataset.csv")

    labels = ["Output1", "Output2"]
    features = ["NumAmostra", "Area", "Delta"]

    scaler = StandardScaler()
    dataset = scaler.fit_transform(raw_dataset[[*labels, *features]])
    dataset = pd.DataFrame(dataset, columns=[*labels, *features])

    X = dataset[features].to_numpy()
    y = dataset[labels].to_numpy()

    X_train, X_test, y_train, y_test = train_test_split(
            X, y, test_size=.3, random_state=0)

    # Model creation   
    model = Model()

    model.add_layer(Dense(3, 4, activation=Sigmoid()))
    model.add_layer(Dense(4, 8, activation=Sigmoid()))
    model.add_layer(Dense(8, 2, activation=Sigmoid()))

    model.compile(loss=MSE())

    history = model.train(X_train, y_train, epochs=epochs, learning_rate=learning_rate)
    
    graphics.plot_loss(history)

    y_pred = model.forward(X_test)

    print("ACC:", accuracy(y_pred, y_test))
