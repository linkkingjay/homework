#include<stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *A, int left, int right)
{
    int i, j, x;
    i = left - 1;
    x = A[right];
    for (j = left; j < right; j++) {
        if (A[j] <= x) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[right]);
    return i + 1;
}
void qsort(int *A, int left, int right)
{
    int q;
    if (left < right) {
        q = partition(A, left, right);
        qsort(A, left, q - 1);
        qsort(A, q + 1, right);
    }
}
int main()
{
    int i;
    int A[9] = {3, 6, 1, 6, 2, 6, 0, 9, 8};
    qsort(A, 0, 8);
    for (i = 0; i < 9; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
