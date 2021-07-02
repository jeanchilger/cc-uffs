import numpy as np

class Layer(object):
    def __init__(self, units, activation=None, input_dim=None, initial_weights=None, use_biases=True):
        self.activation = activation()
        self.units = units
        
        self.weights = initial_weights
        self.biases = None
        self.shape = None
        self._built = False
        self._use_biases = use_biases
        
        if input_dim is not None:
            self.build(input_dim)
        
    def build(self, input_dim):
        self.shape = (input_dim, self.units)
        self._built = True
        
        
        self.weights = np.random.randn(self.units, input_dim) if self.weights is None else self.weights
        self.biases = np.random.randn(self.units) if self._use_biases else np.zeros(self.units)
    
    def forward(self, input_data, training=False):
        if self._built:
            z = np.dot(input_data, self.weights.T) + self.biases
            if training:
                return self.activation(z), z
            else:
                return self.activation(z)
        
        else:
            self.build(len(input_data))
            return self.forward(input_data)
    