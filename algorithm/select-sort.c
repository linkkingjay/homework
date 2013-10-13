#include<stdio.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void select_sort(int *A, int n)
{
    int i, j, t, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        swap(&A[i], &A[min]);
    }
}
int main()
{
    int A[9] = {3,6,1,6,2,6,0,9,8};
    int i;
    select_sort(A, 9);
    for (i = 0; i < 9; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
