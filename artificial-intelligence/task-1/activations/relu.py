import numpy as np
from .function import Function

class ReLU(Function):
    def evaluate(self, x):
        return  x * (x > 0)
    
    def derivative(self, x):
        x[x <= 0] = 0
        x[x > 0] = 1
        
        return x