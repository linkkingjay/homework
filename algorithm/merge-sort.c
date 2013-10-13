#include<stdio.h>
void merge(int *a, int *b, int *c, int na, int nb, int nc)
{
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    if (i == na) {
        while (j < nb)
            c[k++] = b[j++];
    } else {
        while (i < na)
            c[k++] = a[i++];
    }
}

void merge_sort(int *num, int n)
{
    int i, na, nb, a[n], b[n];
    na = n / 2;
    nb = n - na;
    if (n > 1) {
        for (i = 0;i < na; i++) {
            a[i] = num[i];
        }
        for (i = na; i < n; i++) {
            b[i - na] = num[i];
        }

        merge_sort(a, na);
        merge_sort(b, nb);
        merge(a, b, num, na, nb, n);
    }
}

int main()
{
    int num[9] = {3, 6, 1, 6, 2, 6, 0, 9, 8};
    int i;
    merge_sort(num, 9);
    for (i = 0; i < 9; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}


