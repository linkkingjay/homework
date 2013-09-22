#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int F (int);
    int Fib (int);
    int (*Fun)(int);
    int m, n, t;
    char cmd, msg[30];
    time_t st, ct;

    while (scanf("%c", &cmd) != EOF) {
        system("clear");

        if (cmd == '0')
            Fun = F;
        else if (cmd == '1')
            Fun = Fib;
        else continue;

        for(n = 0, time(&st), time(&ct);difftime(st, ct) <= 60;time(&st), n++) {
            t = Fun(n);
            printf("n=%d,Fun(n)=%05d\n", n, t);
        }
    }

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
    for (i = 2;i <= n;i++) {
        temp = f;
        f = (f1 + f2) % 100000;
        f2 = f1;
        f1 = temp;
    }
    return f;
}
