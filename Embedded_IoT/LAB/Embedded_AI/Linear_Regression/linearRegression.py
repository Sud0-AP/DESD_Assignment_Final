import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

#sample data
x = np.array([[1], [2], [3], [4], [5]])
y = np.array([2, 4, 6, 8, 10])

#model
model = LinearRegression()
model.fit(x, y)

#prediction
y_pred = model.predict(x)

print("Slope: ", model.coef_)
print("Intercept: ", model.intercept_)

#plotting
plt.scatter(x, y, color='blue', label='Actual Data')
plt.plot(x, y_pred, color='red', label='Predicted Line')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Linear Regression')
plt.legend()
plt.show()
