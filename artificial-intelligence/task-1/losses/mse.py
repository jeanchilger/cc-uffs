import numpy as np
from .function import Function

class MSE(Function):
    def evaluate(self, y_hat, y):
        return np.mean((y_hat - y) ** 2)
    
    def derivative(self, y_hat, y):
        return y_hat - y