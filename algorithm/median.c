#include<stdio.h>
// 数组的长度
#define N 5
int a[N];
int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}
// 快速排序中的partition
int partition(int *a, int left, int right)
{
    int i, j, x;
    i = left - 1;
    x = a[right];
    for(j = left; j < right; j++) {
        if (a[j] <= x) {
            i++;
            swap(&a[i], &a[j]);            
        }
    }
    swap(&a[i + 1], &a[right]);
    return i + 1;
}

/**
 * @synopsis  求中位数
 *
 * @param a  未排序的整型数组
 * @param left  左边界的下标
 * @param right  右边界的下标
 *
 * @returns  当前数组中的中位数，若长度为奇数则返回正中间的数，若为偶数则返回较
 *           大的那个,即返回的数为a[N / 2];
 */
int median(int *a, int left, int right)
{
    int q;
    if (left < right) {
        q = partition(a, left, right);
        if (q == N / 2) { // 如果q刚好是在中间，即找到了中位数，返回结果
            return a[q];
        } else if (q < N / 2){ // 如果q<N/2，那么说明中位数在右半部分
            return median(a, q + 1, right);
        } else if (q > N / 2){ // 如果q > N / 2，说明中位数在左半部分
            return median(a, left, q - 1);
        }
    }
}
int main()
{
    int i, m;
    for(i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    m = median(a, 0, N - 1);
    printf("%d\n", m);
    return 0;
}
