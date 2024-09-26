# Importing necessary packages
import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets, linear_model
from sklearn.metrics import mean_squared_error, r2_score

# %matplotlib inline # used in jupyter to embeded the result

# loading the dataset and creating its objects
diabetes_data = datasets.load_diabetes()

#Using one feature

X = diabetes_data.data[:, np.newaxis, 2]

# Splitting the data into training and testing sets

X_train = X[: -35]
X_test = X[-35:]
# Splitting the target into training and testing sets

Y_train = diabetes_data.target[:-35]
Y_test = diabetes_data.target[-35:]

# Creating linear regression object
SLR_reg = linear_model.LinearRegression()

# Training the model using the traning sets
SLR_reg.fit(X_train, Y_train)

# Marking predictions by using the testing set
y_pred = SLR_reg.predict(X_test)

# Printing Regression Coefficient, Mean Squared Error (MSE), Variance Score. Also plotting the regression line and labels on it.

print('Coefficients: \n', SLR_reg.coef_)
print("Mean squared error: %.2f"% mean_squared_error(Y_test, y_pred))
print("Variance Score: %.2f" % r2_score(Y_test, y_pred))
plt.scatter(X_test, Y_test, color = "red")
plt.plot(X_test, y_pred, color = "green", linewidth = 3)
plt.xticks(())
plt.yticks(())
plt.show()

