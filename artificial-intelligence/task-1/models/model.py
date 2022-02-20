import numpy as np
import pickle

class Model(object):
    """
    Describes a Model object.
    
    A Model (neural network) is composed of Layers, and must be
    compiled (through the compile method) before used for
    training/prediction.
    """
    
    def __init__(self):
        pass
    
    def save(self, model_path):
        """
        Saves current model into given location.

        Args:
            model_path (str): Model path location.
        """
        
        pickle.dump(self, open(model_path, "wb"))
    
    @classmethod
    def load(self, model_path):
        """
        Loads a model from the given location.

        Args:
            model_path (str): Model path location.

        Returns:
            models.Model: Loaded model instance.
        """
        
        return pickle.load(open(model_path, "rb"))