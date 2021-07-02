import argparse
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from models import Model
from layers import Layer
from activations import Sigmoid
from losses import MSE

parser = argparse.ArgumentParser()

args = parser.parse_args()

if __name__ == "__main__":
    # Data loading
    raw_dataset = pd.read_csv("arruela_dataset.csv")

    labels = ["Output1", "Output2"]
    features = ["NumAmostra", "Area", "Delta"]

    X = raw_dataset[features].to_numpy()
    y = raw_dataset[labels].to_numpy()

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.30, random_state=101)
    
    print(X_train.shape, len(X_train))

    model = Model()
    model.add(Layer(4, input_dim=X_train.shape[1], activation=Sigmoid, initial_weights=np.array([[-0.08,  0.08, -0.03, 0.03],
              [ 0.05,  0.10,  0.07, 0.02],
              [-0.07,  0.04, -0.01, 0.01]]).T, use_biases=False))
    model.add(Layer(2, activation=Sigmoid, initial_weights=np.array([[-0.18,  0.11],
              [-0.09,  0.05],
              [-0.04,  0.05],
              [-0.02,  0.07]]).T, use_biases=False))
    model.compile(loss=MSE)
    
    # model.summary()
    
    model.fit(X_train, y_train, epochs=1000, learn_rate=0.5)
    
    y_pred = model.predict(X_test)
    
    predictions = 0
    n_records, n_features = X_test.shape
    for output, yi in zip(y_pred, y_test):
        if (output[0] > output[1]):
            if (yi[0] > yi[1]):
                predictions+=1
                
        if (output[1] >= output[0]):
            if (yi[1] > yi[0]):
                predictions+=1
                
    print("A Acurácia da Predição é de: {:.3f}".format(predictions/n_records))
