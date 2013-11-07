#include<stdio.h>
#define N 30
#define max(a, b) ((a) > (b) ? (a) : (b))
float x[N];


//float max(float a, float b)
//{
    //return a > b ? a : b;
//}
float arrmax(int n)
{
    if (n == 1) {
        return x[0];
    } else {
        return max(x[n - 1], arrmax(n - 1));
    }
}
int main()
{
    int i = 0;
    float ret;

    for (i = 0; i < N; i++) {
        x[i] = (N - i) * 1.1;
    }
    ret = arrmax(N);
    printf("%f\n", ret);
    return 0;
}
