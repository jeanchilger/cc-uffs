import pandas as pd
import tensorflow as tf
from tensorflow import keras
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from metrics.classification import accuracy

if __name__ == "__main__":
    # Data loading
    raw_dataset = pd.read_csv("arruela_dataset.csv")

    labels = ["Output1"]
    features = ["NumAmostra", "Area", "Delta"]

    X = raw_dataset[features].to_numpy()
    y = raw_dataset[labels].to_numpy()
    
    scaler = StandardScaler()
    X = scaler.fit_transform(X)
    

    X_train, X_test, y_train, y_test = train_test_split(
            X, y, test_size=.3, random_state=0)
    
    model = keras.Sequential()
    model.add(keras.Input(shape=X_train.shape))
    model.add(keras.layers.Dense(9, activation="sigmoid"))
    model.add(keras.layers.Dense(13, activation="sigmoid"))
    model.add(keras.layers.Dense(19, activation="sigmoid"))
    model.add(keras.layers.Dense(13, activation="sigmoid"))
    model.add(keras.layers.Dense(1, activation="sigmoid"))
    
    model.compile(optimizer="adam", loss="binary_crossentropy", metrics=["accuracy"])
    
    model.fit(X_train, y_train, epochs=20000, batch_size=10)
    
    _, y_pred = model.evaluate(X_test, y_test)
    
    print(y_pred)
    # print(y_pred.shape)
    
    # print("@ACC: {:.3f}".format(accuracy(y_pred, y_test)))
    
    # model.summary()