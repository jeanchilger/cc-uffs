import argparse
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

MODEL_PATH="trained_models/best_model/(4x8x16x32x16x2)-activation=sigmoid,loss=mse,epochs=5000,learn_rate=0.5"

if __name__ == "__main__":
    epochs = args.epochs
    learn_rate = args.learn_rate
    
    # Data loading
    raw_dataset = pd.read_csv("arruela_dataset.csv")

    labels = ["Output1", "Output2"]
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
    # model = Model()
    # model.add(Layer(4, input_dim=X_train.shape[1], activation=Sigmoid))
    # model.add(Layer(8, activation=Sigmoid))
    # model.add(Layer(16, activation=Sigmoid))
    # model.add(Layer(32, activation=Sigmoid))
    # model.add(Layer(16, activation=Sigmoid))
    # model.add(Layer(2, activation=Sigmoid))
    # model.compile(loss=MSE)
    
    model = Model.load(MODEL_PATH)
    
    # model.summary()
    
    # history = model.fit(X_train, y_train, epochs=epochs, learn_rate=learn_rate)
    
    model_name = "(4x8x16x2)-activation={},loss={},epochs={},learn_rate={}"
    model_name = model_name.format("sigmoid", "mse", epochs, learn_rate)
    
    # model.save("trained_models/{}".format(model_name))
    
    y_pred = model.predict(X_test)
                
    print("@ACC: {:.3f}".format(accuracy(y_pred, y_test)))
