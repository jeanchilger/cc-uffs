from activations import Linear
import numpy as np
from abc import ABC, abstractmethod

from activations import Function

class Layer(ABC):
    """
    Abstract class to represent a neural network's layer.
    
    A Layer object should implement the forward method,
    wich takes as input a matrix and produces as output
    another matrix.
    
    Also, a Layer should work with "private" _weights and
    _biases, which are further implemented as properties
    (weights and biases), used for training. 
    """
    def __init__(
            self, n_inputs: int, n_outputs: int,
            activation: Function = None):
        self.weights = np.random.randn(n_inputs, n_outputs)
        self.biases = np.random.randn(1, n_outputs)
        self.activation = activation if activation is not None else Linear()
        self.activation_derivative = self.activation.derivative

    @property
    def weights(self):
        return self._weights

    @weights.setter
    def weights(self, weights):
        self._weights = weights

    @property
    def biases(self):
        return self._biases

    @biases.setter
    def biases(self, biases):
        self._biases = biases

    @abstractmethod
    def forward(self, X, training=False):
        pass
    