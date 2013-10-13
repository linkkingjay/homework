#include<stdio.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int bubble_sort(int *A, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 -i; j++) {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        }
    }
}
int main()
{
    int A[9] = {3,6,1,6,2,6,0,9,8};
    int i;
    bubble_sort(A, 9);
    for (i = 0; i < 9; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
