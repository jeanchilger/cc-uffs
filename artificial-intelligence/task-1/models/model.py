import numpy as np
import pickle

class Model(object):
    """
    Describes a Model object.
    
    A Model (neural network) is composed of Layers, and must be
    compiled (through the compile method) before used for
    fitting/prediction.
    """
    
    def __init__(self):
        self.layers = []
        self._compiled = False
        self.loss = None
        self.shape = []
        
    def _backprogate(self, x, y):
        assert self._compiled
        #### Forward pass
        activation = x
        activations = [x]
        inner_products = []
        
        for layer in self.layers:
            activation, z = layer.forward(activation, True)
            
            activations.append(activation)
            inner_products.append(z)
        
        #### Backward pass
        nabla_w = [np.zeros(l.weights.shape) for l in self.layers]
        nabla_b = [np.zeros(l.biases.shape) for l in self.layers]
        
        delta = (y - activations[-1]) * self.layers[-1].activation.derivative(inner_products[-1])
        
        nabla_b[-1] = delta
        nabla_w[-1] = delta * activations[-2].reshape(-1, 1)
        
        for l in range(2, len(self.layers) + 1):
            delta = np.dot(self.layers[-l + 1].weights.T, delta) * self.layers[-l].activation.derivative(inner_products[-l])

            nabla_b[-l] = delta
            nabla_w[-l] = delta * activations[-l-1].reshape(-1, 1)
                
        return nabla_w, nabla_b
    
    def add(self, layer):
        """
        Adds a new Layer instance to the model.
        
        If layer is a input layer, it must be instantiated with
        the input_dim argument set to the number of features.

        Args:
            layer (layers.Layer): Layer instance.
        """

        self.layers.append(layer)
        
    def compile(self, loss):
        """
        Assembles the model's layers such that they are
        correctly 'linked' to each other.
        
        In practice, build method from each layer will be called
        and the right weights and biases dimensions will be set.

        Args:
            loss (losses.Function): Loss function.
        """

        previous_output = self.layers[0].shape[1]
        for layer in self.layers[1:]:
            layer.build(previous_output)
            previous_output = layer.shape[1]
        
        self.loss = loss()
        self._compiled = True
        
    def summary(self):
        """
        Presents the shape of each layer.
        """

        assert self._compiled
        if self._compiled:
            for layer in self.layers:
                print(layer.shape)
                
        else:
            raise Exception("Model is not compiled yet!")
        
    def fit(self, X, y, epochs=100, learn_rate=0.01):
        """
        Fits the model, updating weights and biases.

        Args:
            X (numpy.ndarray): Input data.
            y (numpy.ndarray): Target data.
            epochs (int, optional): Training epochs. Defaults to 100.
            learn_rate (float, optional): [description]. Defaults to 0.01.

        Returns:
            list: The loss history.
        """

        assert self._compiled

        history = []
        for epoch in range(epochs):
            nabla_w = [np.zeros(l.weights.shape) for l in self.layers]
            nabla_b = [np.zeros(l.biases.shape) for l in self.layers]
            
            losses = []
            for _x, _y in zip(X, y):
                delta_nabla_w, delta_nabla_b = self._backprogate(_x, _y)
                nabla_w = [
                    nw + dnw.T
                    for nw, dnw in zip(nabla_w, delta_nabla_w)]
                
                nabla_b = [
                    nb + dnb.T
                    for nb, dnb in zip(nabla_b, delta_nabla_b)]
                    
                losses.append(self.loss(self.predict([_x]), _y))
            
            #### Weights and biases update
            for layer, delta_w, delta_b in zip(self.layers, nabla_w, nabla_b):
                layer.weights = layer.weights + learn_rate * delta_w / len(X)
                layer.biases = layer.biases + learn_rate * delta_b / len(X)
            
            if epoch % (epochs / 20) == 0:
                loss = np.mean(losses)
                print("Average Loss: ", loss)
                history.append(loss)
            
        return history

    def predict(self, X):
        """
        Executes the forward pass in every instance of the given matrix.

        Args:
            X (numpy.ndarray): Input data.

        Returns:
            list: Predictions each position corresponding to a input position.
        """
        
        assert self._compiled
        
        outputs = []
        for x in X:
            output = self.layers[0].forward(x)
            for layer in self.layers[1:]:
                output = layer.forward(output)
                
            outputs.append(output)
                
        return np.array(outputs)
    
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