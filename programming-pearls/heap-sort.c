#include<stdio.h>
int s[10001];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void siftup(int *s, int n)
{
    int i, p;
    for (i = n; i > 1; i = p) {
        p = i / 2;
        if (s[p] >= s[i]) {
            break;
        } else {
            swap(&s[i], &s[p]);
        }
    }
}

void siftdown(int *s, int n)
{
    int i, c;
    for (i = 1; i < n; i = c) {
        c = i * 2;
        if (c > n)
            break;
        if (c + 1 <= n)
            if (s[c] < s[c + 1])
                c++;
        if (s[c] > s[i])
            swap(&s[c], &s[i]);
    }
}

void heap_sort(int *s, int n)
{
    int i;
    for (i = 2; i <= n; i++)
        siftup(s, i);
    for (i = n; i >= 2; i--) {
        swap(&s[1], &s[i]);
        siftdown(s, i - 1);
    }
}
int main()
{
    int i, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }
    heap_sort(s, n);
    for (i = 1; i <= n; i++) {
        printf("%d\n", s[i]);
    }
    return 0;
}
