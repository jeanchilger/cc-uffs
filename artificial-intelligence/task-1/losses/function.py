from abc import ABC, abstractmethod

class Function(ABC):
    """
    Abstract class that represents a function.
    """
    
    def __call__(self, y_hat, y):
        return self.evaluate(y_hat, y)
    
    @abstractmethod
    def evaluate(self, y_hat, y):
        pass
    
    @abstractmethod
    def derivative(self, y_hat, y):
        pass
        
        