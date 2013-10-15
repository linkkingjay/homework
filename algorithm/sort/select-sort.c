void select_sort(int *A, int n)
{
    int i, j, t, min;
    for (i = 0; i < n - 1; i++) {
        for (min = i, j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        swap(&A[i], &A[min]);
    }
}
