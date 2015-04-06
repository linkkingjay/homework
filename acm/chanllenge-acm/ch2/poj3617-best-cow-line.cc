#include <cstdio>

const int MAX_N = 2001;

int i, N, count;
int low, high;
bool left;
char s[MAX_N];

int main() {
    scanf("%d\n", &N);
    for (i = 0; i < N; i++) {
        scanf("%c\n", &s[i]);
    }

    low = 0, high = N - 1;

    count = 0;
    while (low <= high) {
        left = true;
        for (i = 0; low + i < high; i++) {
            if (s[low + i] < s[high - i]) {
                left = true;
                break;
            } else if (s[low + i] > s[high - i]) {
                left = false;
                break;
            }
        }
        if (left) {
            printf("%c", s[low]);
            low++;
        } else {
            printf("%c", s[high]);
            high--;
        }
        if (++count % 80 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
