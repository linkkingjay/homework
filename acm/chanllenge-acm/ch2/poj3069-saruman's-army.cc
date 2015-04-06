#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;

int i, j, k;
int R, n;
int x[MAX_N];
int ans;

int main() {
    while(scanf("%d %d", &R, &n) != EOF && !(R == -1 && n == -1)) {
        ans = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        sort(x, x + n);

        i = 0;
        while (i < n) {
            int s = x[i];

            while (i < n && x[i] <= s + R) {
                i++;
            }

            int p = x[i - 1];

            //printf("p: %d", p);

            while (i < n && x[i] <= p + R) {
                i++;
            }

            //printf(" s: %d\n", x[i]);

            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
