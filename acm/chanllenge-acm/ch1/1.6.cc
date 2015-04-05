#include <cstdio>
#include <math.h>

const int MAX_N = 101;

int n, a[MAX_N];

int max(int a, int b, int c) {
    if (a < b) {
        a = b;
    }
    if (a < c) {
        a = c;
    }
    return c;
}

bool check_triangle(int a, int b, int c) {
    int ma = max(a, b, c);
    if (ma < a + b + c - ma) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int ans = 0;
    int i, j, k, len;;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            for (k = j + 1; k < n; k++) {
                len = a[i] + a[j] + a[k];
                if (check_triangle(a[i], a[j], a[k]) && len > ans) {
                    ans = len;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
