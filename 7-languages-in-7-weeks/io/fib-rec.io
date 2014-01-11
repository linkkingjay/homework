fib := method(n,
    if (n <= 2, return 1, return (fib(n - 1) + fib(n - 2)))
)

for (i, 1, 20, fib(i) println)
