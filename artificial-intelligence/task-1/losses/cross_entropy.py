import numpy as np
from .function import Function

class CrossEntropy(Function):
    def evaluate(self, a, y):
        return - (y * np.log(a) + (1 - y) * np.log(1 - a))
        # return np.sum(np.nan_to_num(-y * np.log(a) - (1 - y) * np.log(1 - a)))
    
    def derivative(self, a, y):
        return y - a
    