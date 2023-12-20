'''
input_1 = int(input("請輸入整數："))
input_2 = int(input("請輸入整數："))
print(input_1+input_2)
print('整數型態：', type(input_1 + input_2))
print(input_1-input_2)
print(input_1*input_2)
print(input_1/input_2)
print(input_1%input_2)
print(input_1//input_2)
print(input_1**input_2)
'''


'''
String1 = '啦課上次二第'
print(String1[::-1])
'''


'''
a = int(input("a:"))
b = int(input("b:"))
if (a == b):
    print("兩數相等")
elif (a < b):
    print("a小於b")
else :
    print("a大於b")
'''


'''
Day = input('請輸入星期幾'):

if Day == '一':
    print('麥當勞')
elif Day == '二':
    print('東門麥當勞')
elif Day == '三':
    print('擄胃專家'):
elif Day == '日':
    print('吃土')
else:
    print('都好')
'''


'''
number1=int(input("請輸入數字1:"))
number2=int(input("請輸入數字2:"))
op=input("請輸入運算:+,-,*,/:")

if(op == '+'):
    print(number1+number2)
elif(op == '-'):
    print(number1-number2)
elif(op == '*'):
    print(number1*number2)
elif(op == '/'):
    print(number1/number2)
else:
    print('不符合條件')
'''


'''
n = 1
while n<5:
    print(n)
    n = n + 1
print('結束了')
'''


'''
list1 = [1,2,3,4,5]
for i in range(5):
    print(list1[i])
'''


'''
for i in range(0,5):
    print(i)
'''


'''
string1 = 'Python'

for i in string1:
    print(i)
for i in range(len(string1)):
    print(i)
    print(string1[i])
'''


'''
for i in range(0,11,2):
    if i == 6:
        print('好')
        break
    print(i)
for i in range(0,11,2):
    if i == 6:
        continue
        print('好了')
    print(i)
'''


'''
n = 0
for i in range(101):
    n += i
print(n)
'''


'''
n1 = int(input('請輸入數字:'))
n2 = 1
for i in range(1,n1+1): 
    if n1%i == 0:
        print(i)
while n2 <= n1:
    if n1%n2 == 0:
        print(n2)
    n2 += 1
'''


'''
Class_1 = ['B177793449','A134689794',
'G130949062','K147378503'
,'B200674844','B163671690','B205054646',
'E231081836','D219055993','D183361919'
,'X161067471','B281840622','B153971781',
'N151829346','B283079309']

Taichung_people = []
Taichung_man = []
Taichung_woman = []
for i in Class_1:
    if i[0] == 'B':
        Taichung_people.append (i)
        if i[1] == '1':
            Taichung_man.append (i)
        else:
            Taichung_woman.append (i)
print('有',len(Taichung_people),'個台中人')
print('有',len(Taichung_man),'個台中男生')
print('有',len(Taichung_woman),'個台中女生')
'''