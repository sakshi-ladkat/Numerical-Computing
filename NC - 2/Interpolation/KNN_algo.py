import numpy as np
import pandas as pd 
from sklearn.model_selection import train_test_split
from sklearn.datasets import load_iris

iris = load_iris()

x = iris.data
y = iris.target


X_train , X_test , y_train ,y_test =train_test_split(x,y,test_size=0.2,random_state=None)

def distance(a,b):
    return np.sqrt(np.sum(a-b)**2)

k = 3
pred = []
for j in range(len(X_test)):
    d = []
    for i in range(len(X_train)):
        d.append(distance(X_test[j],X_train[i]))

    tmp = y_train[np.argsort(d)[:k]]
    y_pred = pd.Series(tmp).value_counts().index[0]
    pred.append(y_pred)

accuracy = sum(pred == y_test)/len(y_test)

from sklearn.metrics import confusion_matrix