from abc import ABC, abstractmethod

class Function(ABC):
    """
    Abstract class that represents a function.
    """
    
    def __call__(self, x):
        return self.evaluate(x)
    
    @abstractmethod
    def evaluate(self, x):
        pass
    
    @abstractmethod
    def derivative(self, x):
        pass
        
        