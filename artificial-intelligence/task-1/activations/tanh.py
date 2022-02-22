import numpy as np
from .function import Function

class TanH(Function):
    def evaluate(self, x):
        return np.tanh(x)
    
    def derivative(self, x):
        return 1 - (self.evaluate(x) ** 2)
    