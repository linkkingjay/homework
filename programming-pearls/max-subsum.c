#include<stdio.h>
int s[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
int max(int a, int b) {
    return a > b ? a : b;
}
int main()
{
    int max_sofar, max_endhere;
    int i;
    max_sofar = max_endhere = 0;
    for (i = 0; i < 10; i++) {
        max_endhere = max(max_endhere + s[i], 0);
        max_sofar = max(max_sofar, max_endhere);
    }
    printf("%d\n", max_sofar);
    return 0;
}
