import numpy as np
from .function import Function

class MSE(Function):
    def evaluate(self, a, y):
        return np.mean((a - y) ** 2)
    
    def derivative(self, a, y):
        return y - a
    