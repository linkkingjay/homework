#include<stdio.h>
#include<time.h>
int main()
{
    int F (int);
    int Fib (int);
    int n;
    time_t st, ct;

    for(n = 0, time(&st), time(&ct);difftime(st, ct) <= 60;time(&st), n++)
        printf("n=%d,Fib(n)=%05d\n", n, Fib(n));

    return 0;
}

/*
 * 基于定义的递归算法
 */
int F(int n)
{
    if (n <= 1)
        return 1;
    else
        return (F(n-1) + F(n-2)) % 100000;
}

/*
 * 基于定义的循环算法
 */
int Fib(int n)
{
    int i, f, f1, f2, temp;
    f1 = 1;
    f2 = 0;
    for (i = 2;i <= n;i++)
    {
        temp = f;
        f = (f1 + f2) % 100000;
        f2 = f1;
        f1 = temp;
    }
    return f;
}
