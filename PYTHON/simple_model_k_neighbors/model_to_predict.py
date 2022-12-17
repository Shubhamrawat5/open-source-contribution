from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import GridSearchCV
import matplotlib.pyplot as plt
import pandas as pd

# load iris data
iris = load_iris()


# split data
X_train, X_test, y_train, y_test = train_test_split(iris.data, iris.target, random_state=0)
# Search for the optimal hyperparameter 
N_range = list(range(1, 18))
knn = KNeighborsClassifier(n_jobs=-1)
param_grid = {'n_neighbors':N_range ,'weights':["uniform", "distance"]}

grid = GridSearchCV(knn, param_grid, cv=10, scoring='accuracy', return_train_score=False)
grid.fit(X_train, y_train)


print('This is the score of the training : ' , grid.best_score_)
print('Best parameters is  ' , grid.best_params_)
print('Best estimators : ' , grid.best_estimator_)
#Evaluation and calculate the model accuracy
grid.best_estimator_.fit(X_train,y_train)
out=grid.score(X_test,y_test)
print(f"This is model accuracy {out}")