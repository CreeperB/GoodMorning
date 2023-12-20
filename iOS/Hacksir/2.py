'''
yr = int(input("輸入西元年："))
if yr % 4 == 0:
    if yr % 100 == 0 and yr % 400 != 0:
        print("平年")
    elif yr % 400 == 0:
        print("閏年")
    else:
        print("閏年")
else:
    print("平年")
'''


'''
import random
guess = 0
answer = random.randrange(1,100)
while guess != answer:
    guess = int(input("Guess the number:"))
    if guess < answer:
        print("Bigger")
    elif guess > answer:
        print("Smaller")
print("You're correct")
print("Game over")
'''


'''
for i in range(1, 10):
    for j in range(1, 10):
        # print(str(i) + '*' + str(j) + '=' + str(i * j), end=" ")
        print(f'{i}*{j}={i*j} ',end='')
    print('')
    print('')
'''


'''
name = 'Tommy'
age = 19
country = 'Taiwan'
print('My name is %s, %d years old, come from %s' % (name, age, country))
print('My name is {}, {} years old, come from {}' .format(name, age, country))
print(f'My name is {name}, {age} years old, come from {country}')
'''


'''
squares = {}
for i in range(1,10):
    squares[i] = i**2
print("Squares = ",squares)
'''


'''
list = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
]
for i in list:
    for j in i:
        print(j)
'''



