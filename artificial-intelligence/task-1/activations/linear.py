from .function import Function

class Linear(Function):
    def evaluate(self, x):
        return x
    
    def derivative(self, x):
        return x