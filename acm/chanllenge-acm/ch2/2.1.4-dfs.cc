#include <cstdio>
const int MAX_N = 1000000;
int a[MAX_N];
int i, n, k;

bool dfs(int i, int sum) {
    if (i == n) {
        return sum == k;
    }
    if (dfs(i + 1, sum)) {
        return true;
    }
    if (dfs(i + 1, sum + a[i + 1])) {
        return true;
    }

    return false;
}
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);

    if (dfs(0, 0)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}
