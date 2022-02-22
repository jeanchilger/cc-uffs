from pprint import pprint
import numpy as np
from .function import Function

class CrossEntropy(Function):
    def evaluate(self, y_hat, y):
        n = y_hat.shape[0]
    
        return -np.sum(y * np.log(y_hat) + (1 - y) * np.log(1 - y_hat)) / n
    
    def derivative(self, y_hat, y):
        return y_hat - y
    