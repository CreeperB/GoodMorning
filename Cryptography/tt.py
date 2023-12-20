pf = [[], [], [], [], []]
for i in range(5):
    pf[i] = input()

m = input()
nl = input()


def find_index(c):
    row, col = -1, -1
    for i in range(5):
        try:
            row = i
            col = pf[i].index(c)
            break
        except ValueError:
            continue
    if row == -1 and c == 'j':
        find_index('i')
    return row, col


l = len(m)
index = 0
while index < l:
    # for i in range(0, len(m), 2):
    if m[index] == m[index + 1]:
        m = m[:index + 1] + nl + m[index + 1:]
        l += 1
    # print(m[index], m[index + 1])
    row1, col1 = find_index(m[index])
    row2, col2 = find_index(m[index + 1])
    if row1 == row2:
        print(pf[row1][(col1 + 1) % 5], end='')
        print(pf[row2][(col2 + 1) % 5], end='')
    elif col1 == col2:
        print(pf[(row1 + 1) % 5][col1], end='')
        print(pf[(row2 + 1) % 5][col2], end='')
    else:
        print(pf[row1][col2], end='')
        print(pf[row2][col1], end='')
    index += 2
