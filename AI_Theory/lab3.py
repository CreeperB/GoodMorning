import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets, linear_model
import random

length = 10
# X = [[0.31], [0.45], [0.48], [0.55], [0.70], [0.88], [0.98], [1.05], [1.11], [1.22]]
X = [[random.random()] for i in range(length)]
# y = [10000, 12000, 14000, 18000, 22000, 28000, 32000, 36000, 40000, 48000]
y = [i[0] * random.randint(10000, 50000) for i in X]

regr = linear_model.LinearRegression()
regr.fit(X, y)

y_pre = regr.predict(X)

plt.scatter(X, y, color='black')
plt.plot(X, y_pre, color='blue', linewidth=3)

plt.xlabel("carat")
plt.ylabel("price")

print("平均誤差: ", sum(abs(y[i] - y_pre[i]) for i in range(len(y))) / len(y))
plt.show()