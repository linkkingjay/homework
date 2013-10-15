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
