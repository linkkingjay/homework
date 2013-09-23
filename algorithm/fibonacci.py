def F(n):
    if n <= 1:
        return 1
    else:
        return (F(n - 1) + F(n -2)) % 100000

def Fib(n):
    f1 = 1
    f2 = 0
    f = 2
    for i in range(1, n + 1):
        t = f
        f = (f1 + f2) % 100000
        f2 = f1
        f1 = t
    return f

def main():
    for n in range(0, 1000000):
        print "n=%d, Fun(n)=%d" % (n, Fib(n))

if __name__ == '__main__':
    main()
