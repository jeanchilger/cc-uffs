import numpy as np
from .function import Function

class Sigmoid(Function):
    def evaluate(self, x):
        return 1.0 / (1.0 + np.exp(-x))
    
    def derivative(self, x):
        return self.evaluate(x) * (1 - self.evaluate(x))
    