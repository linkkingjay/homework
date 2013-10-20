#define LEN 30
void merge(char a[][LEN], char b[][LEN], char c[][LEN], int na, int nb, int nc)
{
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] <= b[j]) {
            strcpy(c[k], a[i]);
            i++;
        } else {
            strcpy(c[k], b[j]);
            j++;
        }
        k++;
    }
    if (i == na) {
        while (j < nb) {
            strcpy(c[k++], b[j++]);
        }
    } else {
        while (i < na) {
            strcpy(c[k++], a[i++]);
        }
    }
}

void merge_sort(char array[][LEN], int n, int (*cmp)(char *, char *))
{
    int i, na, nb;
    char a[n][LEN], b[n][LEN];
    na = n / 2;
    nb = n - na;
    if (n > 1) {
        for (i = 0;i < na; i++) {
            strcpy(a[i], array[i]);
        }
        for (i = na; i < n; i++) {
            strcpy(b[i - na], array[i]);
        }

        merge_sort(a, na, cmp);
        merge_sort(b, nb, cmp);
        merge(a, b, array, na, nb, n);
    }
}
