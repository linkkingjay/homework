void select_sort(char array[][30], int n, int (*cmp)(char *, char *))
{
    int i, j, t, min;
    for (i = 0; i < n - 1; i++) {
        for (min = i, j = i + 1; j < n; j++) {
            if (cmp(array[j], array[min]) > 0) {
                swap(array[j], array[min]);
            }
        }
    }
}
