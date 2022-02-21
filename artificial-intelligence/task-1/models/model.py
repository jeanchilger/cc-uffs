import numpy as np
import pickle
from tqdm import tqdm

from layers import Layer
from losses import Function

class Model(object):
    """
    Describes a Model object.
    
    A Model (neural network) is composed of Layers, and must be
    compiled (through the compile method) before used for
    training/prediction.
    """
    
    def __init__(self):
        self._layers = []
        self._losses = None
    
    def add_layer(self, layer: Layer) -> None:
        """
        Adds a layer to the model. The order of the layers
        depends on the order they were added.

        Args:
            layer (Layer): _description_
        """

        self._layers.append(layer)

    def forward(self, x: np.ndarray) -> np.ndarray:
        """
        Pass the input through the layers, calling
        the forward method of each of them.

        Args:
            x (np.ndarray): Input data.

        Returns:
            np.ndarray: Result from the forward pass.
        """

        assert type(x) is np.ndarray
        
        for l in self._layers:
            x = l.forward(x)
            
        return x
    
    def predict(self, X: np.ndarray) -> np.ndarray:
        return self.forward(X)
    
    def train(
            self, X: np.ndarray, y: np.ndarray,
            epochs: int = 10, learning_rate: float = 1e-2) -> None:
        """
        Trains the model, updating the layers' weights.

        Args:
            X (np.ndarray): Training data.
            y (np.ndarray): Training labels.

        """

        history = []

        for epoch in range(epochs):
            deltas_w = [np.zeros(l.weights.shape) for l in self._layers]
            deltas_b = [np.zeros(l.biases.shape) for l in self._layers]
            
            for xi, yi in (bar := tqdm(list(zip(X, y)))):
                bar.set_description(f"Epoch {epoch}")

                d_w, d_b = self._backpropagate(xi, yi)

                deltas_w = [dw + diw for dw, diw in zip(deltas_w, d_w)]
                deltas_b = [db + dib for db, dib in zip(deltas_b, d_b)]

            for i in range(len(self._layers)):
                l = self._layers[i]

                l.weights = l.weights - learning_rate * deltas_w[i]
                l.biases = l.biases - learning_rate * deltas_b[i]

            history.append(self.loss(y, self.predict(X)))

        return history

    def _backpropagate(self, x, y):
        # FORWARD PASS
        ## Compute activations for each layer, storing
        ## them and the inner products
        a = x
        activations = [x]
        inner_products = []
        for l in self._layers:
            a, z = l.forward(a, training=True)
            activations.append(a)
            inner_products.append(z)

        # BACKWARD PASS
        ## Initialize vectors for update rate of weights and biases
        deltas_w = [np.zeros(l.weights.shape) for l in self._layers]
        deltas_b = [np.zeros(l.biases.shape) for l in self._layers]
        
        ## First, compute deltas for last (output) layer
        z = inner_products[-1]

        delta = (self.loss_derivative(y, activations[-1])
                * self._layers[-1].activation_derivative(z))

        deltas_w[-1] = np.dot(activations[-2].reshape(-1, 1), delta.reshape(1, -1))
        deltas_b[-1] = delta

        ## Compute deltas for the rest of the layers. Delta for
        ## ith layer is taken in terms of the delta of the
        ## (i + 1)th layer.                
        for i in range(2, len(self._layers) + 1):
            z = inner_products[-i]
            a = activations[-i - 1].reshape(-1, 1)

            delta = (np.dot(delta, self._layers[-i + 1].weights.T)
                    * self._layers[-i].activation_derivative(z))

            deltas_w[-i] = np.dot(a, delta)
            deltas_b[-i] = delta

        return deltas_w, deltas_b

    def compile(self, loss: Function) -> None:
        self._loss = loss

    def loss(self, y_true, y_pred):
        return self._loss(y_pred, y_true)
    
    def loss_derivative(self, y_true: np.ndarray, y_pred: np.ndarray) -> np.ndarray:
        return self._loss.derivative(y_pred, y_true)
    
    def save(self, model_path: str) -> None:
        """
        Saves current model into given location.

        Args:
            model_path (str): Model path location.
        """
        
        pickle.dump(self, open(model_path, "wb"))
    
    @classmethod
    def load(self, model_path: str):
        """
        Loads a model from the given location.

        Args:
            model_path (str): Model path location.

        Returns:
            Model: Loaded model instance.
        """
        
        return pickle.load(open(model_path, "rb"))