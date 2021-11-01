# get iris data from sklearn
import sklearn
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score

# load iris data
iris = load_iris()


# split data
X_train, X_test, y_train, y_test = train_test_split(
    iris.data, iris.target, random_state=0)

# train model
knn = KNeighborsClassifier(n_neighbors=1)
knn.fit(X_train, y_train)

# predict
y_pred = knn.predict(X_test)

# evaluate
print(accuracy_score(y_test, y_pred))
