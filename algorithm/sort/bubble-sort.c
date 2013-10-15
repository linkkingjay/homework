void bubble_sort(int *A, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 -i; j++) {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        }
    }
}
