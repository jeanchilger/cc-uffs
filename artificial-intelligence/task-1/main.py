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
from sklearn.model_selection import KFold
from sklearn.model_selection import cross_val_score

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
    raw_dataset = pd.read_csv("arruela_.csv")

    labels = ["Output1", "Output2"]
    features = ["NumAmostra", "Area", "Delta"]
    
    scaler = StandardScaler()
    dataset = scaler.fit_transform(raw_dataset[[*features]])
    dataset = pd.DataFrame(dataset, columns=[*features])

    X = dataset[features].to_numpy()
    y = raw_dataset[labels].to_numpy()

    # X_train, X_test, y_train, y_test = train_test_split(
    #         X, y, test_size=.3, random_state=0)

    # Model creation
    ##
    m1 = Model()

    m1.add_layer(Dense(3, 4, activation=Sigmoid()))
    m1.add_layer(Dense(4, 16, activation=Sigmoid()))
    m1.add_layer(Dense(16, 8, activation=Sigmoid()))
    m1.add_layer(Dense(8, 2, activation=Sigmoid()))

    m1.compile(loss=MSE())
    
    ##
    m2 = Model()

    m2.add_layer(Dense(3, 24, activation=Sigmoid()))
    m2.add_layer(Dense(24, 2, activation=Sigmoid()))

    m2.compile(loss=MSE())
    
    ##
    m3 = Model()

    m3.add_layer(Dense(3, 8, activation=Sigmoid()))
    m3.add_layer(Dense(8, 2, activation=Sigmoid()))

    m3.compile(loss=MSE())
    
    ##
    m4 = Model()

    m4.add_layer(Dense(3, 8, activation=Sigmoid()))
    m4.add_layer(Dense(8, 54, activation=Sigmoid()))
    m4.add_layer(Dense(54, 8, activation=Sigmoid()))
    m4.add_layer(Dense(8, 2, activation=Sigmoid()))

    m4.compile(loss=MSE())
    
    ##
    m5 = Model()

    m5.add_layer(Dense(3, 124, activation=Sigmoid()))
    m5.add_layer(Dense(124, 2, activation=Sigmoid()))

    m5.compile(loss=MSE())
    
    models = {
        "3x4x16x8x2": m1,
        "3x24x2": m2,
        "3x8x2": m3,
        "3x8x54x8x2": m4,
        "3x124x2": m5,
    }

    cv = KFold(n_splits=10, random_state=1, shuffle=True)
    cv_scores = {}
    
    for m_name, model in models.items():
        cv_scores[m_name] = []
        for train_idx, test_idx in cv.split(X, y):
            X_train = X[train_idx]
            y_train = y[train_idx]
            X_test = X[test_idx]
            y_test = y[test_idx]
            
            history = model.train(
                    X_train, y_train, epochs=epochs,
                    learning_rate=learning_rate, verbose=False)

            y_pred = model.forward(X_test)
            cv_scores[m_name].append(accuracy(y_pred, y_test))
            
    for m_name, scores in cv_scores.items():
        print("===========================")
        print(m_name)
        print("Acurácia Média: {:.4f}%".format(np.mean(scores)))
        print("Desvio padrão: {:.4f}%".format(np.std(scores)))
        
        print("===========================\n\n")
    
    # evaluate model

    # history = model.train(
    #         X_train, y_train, epochs=epochs,
    #         learning_rate=learning_rate)
        
    # y_pred = model.forward(X_test)
    # print("ACC:", accuracy(y_pred, y_test))

    # graphics.plot_loss(history)
    
    # model.save(f"trained_models/3x4x8x2-Sigmoid-MSE-e{epochs}-l{learning_rate}")
