# from lab import vector_plus_one, collatz_steps, exchange_matrix, get_nonzero, Dual_Iterator, frange, mulDigits, getCount
vector_plus_one = lambda lst: [x + 1 for x in lst]
collatz_steps = lambda lst: [3 * n + 1 if n % 2 else n // 2 for n in lst if isinstance(n, int) and n > 0]
exchange_matrix = lambda size: [[1 if i + j == size - 1 else 0 for j in range(size)] for i in range(size)]
get_nonzero = lambda matrix: [(i, j) for i, row in enumerate(matrix) for j, val in enumerate(row) if val != 0]

def mulDigits(num, fn):
    """
        >>> isTwo = lambda num: num == 2
        >>> mulDigits(5724892472, isTwo)
        8
        >>> def divByFour(num):
        ...     return not num%4
        ...
        >>> mulDigits(5724892472, divByFour)
        128
        >>> mulDigits(155794, isTwo)
        1
        >>> mulDigits(67945125482222152, isTwo)
        64
        >>> mulDigits(679451254828822152, divByFour)
        8192
    """
    result = 1
    while num > 0:
        digit = num % 10
        if fn(digit):
            result *= digit
        num //= 10
    return result

def getCount(x):
    """
        >>> getCount(6)(62156)
        2
        >>> digit = getCount(7)
        >>> digit(9457845778457077076)
        7
        >>> digit(-945784578457077076)
        6
        >>> getCount(6)(-65062156)
        3
    """
    def count_x_digits(num):
        num = abs(num)
        count = 0
        while num != 0:
            if num % 10 == x:
                count += 1
            num //= 10
        return count
    return count_x_digits

class Dual_Iterator:    
    """
        >>> it = Dual_Iterator([2, 4, 6, 8, 10]) 
        >>> next(it)
        2
        >>> next(it)
        4
        >>> next(it)
        6
        >>> it.reverse()
        >>> next(it)
        4
        >>> next(it)
        2
        >>> next(it)
        10
        >>> it.reverse()
        >>> next(it)
        2
        >>> next(it)
        4
        >>> next(it)
        6
        >>> it.reverse()
        >>> next(it)
        4
        >>> next(it)
        2
        >>> next(it)
        10
        >>> next(it)
        8
        >>> next(it)
        6
        >>> it2 = Dual_Iterator([2, 4, 6, 8, 10]) 
        >>> [next(it2) for _ in range(12)]
        [2, 4, 6, 8, 10, 2, 4, 6, 8, 10, 2, 4]
        >>> it2.reverse()
        >>> [next(it2) for _ in range(12)]
        [2, 10, 8, 6, 4, 2, 10, 8, 6, 4, 2, 10]
    """
    def __init__(self, sequence):
        self.sequence = sequence
        self.index = 0
        self.reverse_direction = False

    def __iter__(self): # Do not modify
        return self

    def __next__(self):
        if not self.reverse_direction:
            value = self.sequence[self.index]
            self.index = (self.index + 1) % len(self.sequence)
        else:
            self.index = (self.index - 1) % len(self.sequence)
            value = self.sequence[self.index - 1]
        return value

    def reverse(self):
        self.reverse_direction = not self.reverse_direction
    
from decimal import Decimal
    
def frange(*args):
    '''
        >>> list(frange(7.5))
        [0, 1, 2, 3, 4, 5, 6, 7]
        >>> seq = frange(0,7, 0.1)
        >>> type(seq)
        <class 'generator'>
        >>> list(seq)
        [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6, 4.7, 4.8, 4.9, 5.0, 5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7, 5.8, 5.9, 6.0, 6.1, 6.2, 6.3, 6.4, 6.5, 6.6, 6.7, 6.8, 6.9]
        >>> list(seq)
        []
        >>> list(frange(0,7, 0.75))
        [0, 0.75, 1.5, 2.25, 3.0, 3.75, 4.5, 5.25, 6.0, 6.75]
        >>> list(frange(0,7.75, 0.75))
        [0, 0.75, 1.5, 2.25, 3.0, 3.75, 4.5, 5.25, 6.0, 6.75, 7.5]
        >>> list(frange(0,7.75, -0.5))
        []
        >>> list(frange(7.75,0, -0.5))
        [7.75, 7.25, 6.75, 6.25, 5.75, 5.25, 4.75, 4.25, 3.75, 3.25, 2.75, 2.25, 1.75, 1.25, 0.75, 0.25]
    '''
    start, step = 0, 1

    if len(args) == 1:
        stop = args[0]
    elif len(args) == 2:
        start, stop = args
    elif len(args) == 3:
        start = args[0]
        stop = args[1]
        step = args[2]
    else:
        raise TypeError(f'frange expected at most 3 arguments, got {len(args)}')
    
    ifStartInt = False if type(start) == float else True
    
    if type(step) == float or type(start) == float:
        start, stop, step = Decimal(str(start)), Decimal(str(stop)), Decimal(str(step))
        current = start
        while (step > 0 and current < stop) or (step < 0 and current > stop):
            if current == start and ifStartInt:
                yield int(current)
            else:
                yield float(current)
            current += step
    else:
        current = start
        while (step > 0 and current < stop) or (step < 0 and current > stop):
            yield int(current)
            current += step
            
'''
# ========= TESTING ASSERTIONS FOR PART 1 - DO NOT MODIFY ================

def test_vector_plus_one():
    assert vector_plus_one([1, 2, 3]) == [2, 3, 4]
    assert vector_plus_one([0, 0, 0]) == [1, 1, 1]
    assert vector_plus_one([-1, -2, -3, -4, -5]) == [0, -1, -2, -3, -4]
    assert vector_plus_one([]) == []
    print('All cases for vector_plus_one passed!')

def test_collatz_steps():
    assert collatz_steps([1, 2, 3, 4]) == [4, 1, 10, 2]
    assert collatz_steps([0, "", -2, 1.5, 2.0]) == []
    assert collatz_steps([-1, -2, -3, -4, -5]) == []
    assert collatz_steps([]) == []
    print('All cases for collatz_steps passed!')


def test_exchange_matrix():
    assert exchange_matrix(1) == [[1]]
    assert exchange_matrix(2) == [[0, 1], [1, 0]]
    assert exchange_matrix(3) == [[0, 0, 1], [0, 1, 0], [1, 0, 0]]
    print('All cases for exchange_matrix passed!')


def test_get_nonzero():
    assert get_nonzero([[1, 0, 0], [0, 2, 0], [0, 0, 3]]) == [(0, 0), (1, 1), (2, 2)]
    assert get_nonzero([[-1, 0, 0], [0, 0, 0], [0, 0, -3]]) == [(0, 0), (2, 2)]
    assert get_nonzero([[0, 0, 0], [0, 0, 0], [0, 0, 0]]) == []
    print('All cases for get_non_zero passed!')



# ========= STARTER TESTING ================

def run_tests():
    # For Part 1
    #-- Uncomment function per function to test
    test_vector_plus_one()
    test_collatz_steps()
    test_exchange_matrix()
    test_get_nonzero()

    # For Part 2
    import doctest    
    # -- Run tests per function - Uncomment the next line to run doctest by function. Replace mulDigits with the name of the function you want to test
    doctest.run_docstring_examples(mulDigits, globals(), name='LAB8',verbose=True)
    doctest.run_docstring_examples(getCount, globals(), name='LAB8',verbose=True)
    doctest.run_docstring_examples(frange, globals(), name='LAB8',verbose=True)
    doctest.run_docstring_examples(Dual_Iterator, globals(), name='LAB8',verbose=True)



if __name__ == "__main__":
    run_tests()
'''