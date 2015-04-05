#include <cstdio>
int L, n;
int min(int a, int b) {
    return a > b ? b : a;
}
int max(int a, int b) {
    return a < b ? b : a;
}
int main() {
    int x, i, k, min_ans, max_ans;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &L);
        scanf("%d", &n);
        min_ans = 0;
        max_ans = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            min_ans = max(min(L- x, x), min_ans);
            max_ans = max(max(L- x, x), max_ans);
        }

        printf("%d %d\n", min_ans, max_ans);
    }
    return 0;
}
