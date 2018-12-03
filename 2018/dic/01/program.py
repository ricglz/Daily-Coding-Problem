# For this case I used python because this is a problem perfect for functional
# paradigm languages, and that would have been a lot more difficult in a
# language like c++ that is object oriented
def cons(a, b):
    return lambda f: f(a, b)

def car(f):
    return f(lambda a, b: a)

def cdr(f):
    return f(lambda a, b: b)

if __name__ == '__main__':
    # Read input of two numbers, separated by commas
    a, b = (int(n) for n in input().split(','))
    print(car(cons(a, b)))
    print(cdr(cons(a, b)))
