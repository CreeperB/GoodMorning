from keras.models import Sequential
from keras.layers import Dense

model = Sequential()
model.add(Dense(50, input_shape=784, activation='relu'))