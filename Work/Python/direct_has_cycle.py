from scipy.sparse import *
import numpy as np


def p1_has_cycle(sets):
    n = len(sets)
    tmp = csr_matrix(sets)
    while n > 0:
        y = np.where(tmp[0].toarray() == 1)[1][0]
        x = np.where(tmp.getcol(y).toarray() == -1)[0]
        for col in x:
            if (tmp[0] + tmp[col]).min() == 0:
                return True
            tmp = vstack([tmp, tmp[0] + tmp[col]])
        tmp = csr_matrix(tmp[1:])
        n += len(x) - 1
    return False


def p2_has_cycle(sets):
    n = len(sets)
    tmp = csr_matrix(sets)
    ori = tmp
    for _ in range(n):
        tmp = tmp.dot(ori)
        if tmp.diagonal > 0:
            return True
    return False


if __name__ == "__main__":
    sets = list([
        # [0, 1, -1, 0],
        # [1, -1, 0, 0],
        # [-1, 0, 1, 0],
        # [0, -1, 0, 1],
        [0, 0, 1, 0],
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 1, 0, 0],
    ])
    # print(p1_has_cycle(sets))
    print(p2_has_cycle(sets))