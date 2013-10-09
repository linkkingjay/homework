#include<stdio.h>
int binary_search(int *A, int k, int n)
{
    int l, r, m;
    l = 0;
    r = n - 1;
    while (l <= r) {
        m = (l + r) / 2;
        if (k == A[m]) {
            return m;
        } else {
            if (k < A[m])
                r = m - 1;
            else
                l = m + 1;
        }
    }
    return -1;
}
