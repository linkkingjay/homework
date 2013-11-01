#include<stdio.h>
#include<stdlib.h>
#define N 32
void copy(int a[N + 1][N + 1], int n)
{
    int i, j;
    int m = n / 2;
    printf("m=%d\n", m);
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= m; j++) {
            a[i][j + m] = a[i][j] + m;
            a[i + m][j] = a[i][j + m];
            a[i + m][j + m] = a[i][j];
        }
    }
}
void foo(int a[N + 1][N + 1], int n)
{
    if (n == 1) {
        a[1][1] = 1;
        return;
    } else {
        foo(a, n / 2);
        copy(a, n);
    }
}
int main()
{
    int a[N + 1][N + 1];
    int i, j;
    foo(a, N);
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
