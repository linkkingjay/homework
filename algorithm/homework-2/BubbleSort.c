void bubble_sort(char array[][30], int n, int (*cmp)(char *, char *))
{
    int i, j;


    // 冒泡排序核心部分
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (cmp(array[j], array[j + 1]) > 0) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}
