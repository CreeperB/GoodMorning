def next_alpha(s, i):
    return chr((ord(s.upper()) + i - ord('A')) % 26 + ord('A'))


buf = input()
key = input()
j = 0
for i in buf:
    if i.isalpha():
        print(next_alpha(i, ord(key[j % len(key)]) - ord('a')), end='')
        j += 1
    else:
        print(i, end='')