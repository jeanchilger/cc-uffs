from abc import ABC, abstractmethod

class Function(ABC):
    """
    Abstract class that represents a function.
    """
    
    def __call__(self, a, y):
        return self.evaluate(a, y)
    
    @abstractmethod
    def evaluate(self, a, y):
        pass
    
    @abstractmethod
    def derivative(self, a, y):
        pass
        
        