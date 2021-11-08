import matplotlib.pyplot as plt

def plot_loss(history, color="red"):
    plt.plot(list(range(len(history))), history, color)
    plt.xlabel("Iterations")
    plt.ylabel("Loss")
    plt.show()