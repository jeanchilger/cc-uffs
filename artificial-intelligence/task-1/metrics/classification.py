def accuracy(y_pred, y_true):
    right_predictions = 0
    
    for yp, yt in zip(y_pred, y_true):
        if yp[0] > yp[1]:
            if yt[0] > yt[1]:
                right_predictions += 1
                
        if yp[1] >= yp[0]:
            if yt[1] > yt[0]:
                right_predictions += 1
                
    return right_predictions / len(y_pred)