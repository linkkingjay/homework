#include <cstdio>

int V[6] = {1, 5, 10, 50, 100, 500};
int C[6], A;

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
int main() {
    int ret = 0;
    scanf("%d %d %d %d %d %d %d", &C[0], &C[1], &C[2], &C[3], &C[4], &C[5], &A);

    for (int i = 5; i >= 0; i--) {
        int t = min(int(A / V[i]), C[i]);
        A -= t * V[i];
        ret += t;
    }

    printf("%d\n", ret);

    return 0;
}
