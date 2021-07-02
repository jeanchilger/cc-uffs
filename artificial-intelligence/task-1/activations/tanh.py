import numpy as np
from .function import Function

class TanH(Function):
    def evaluate(self, x):
        return 2.0 / (1.0 + np.exp(-2.0 * x)) - 1
    
    def derivative(self, x):
        return 1 - (self.evaluate(x) ** 1)
    