import numpy as np

from activations import Function
from .layer import Layer

class Dense(Layer):
    """
    A Dense layer simply computes the dot product between input and
    weights, sum with the biases and apply the activation function.
    """

    def __init__(
            self, n_inputs: int, n_outputs: int,
            activation: Function = None):
        super().__init__(n_inputs, n_outputs, activation)
    
    def forward(self, inputs):
        assert type(inputs) is np.ndarray
        
        z = np.dot(inputs, self.weights) + self.biases
        return self.activation(z)
