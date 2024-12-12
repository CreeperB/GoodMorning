import tensorflow as tf

w = tf.Variable([3.], dtype=tf.float32)
x = tf.Variable([2.], dtype=tf.float32)
b = tf.Variable([5.], dtype=tf.float32)

print(w * x + b)
o = tf.sigmoid(w * x + b)
print(o)