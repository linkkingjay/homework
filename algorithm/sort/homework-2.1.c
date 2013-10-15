/**
 * @file homework-2.1.c
 * @synopsis  用选择排序和冒泡排序给制定文件排序并输出文本文件
 * @author linkkingjay
 * @version 1.0
 * @date 2013-10-14
 */
#include<stdio.h>
#include<time.h>
#define N 10000

#include "sort.h"
int main()
{
    void print(int *, int);
    void test(void func(int *, int), int *A, int n);
    int A[N];
    int i;
    time_t bt, et;
    FILE * data;

    data = fopen("data.txt", "r");
    for (i = 0; i < N; i++) {
        fscanf(data, "%d", &A[i]);
    }

    print(A, N);

    //test(select_sort, A, N);
    //test(bubble_sort, A, N);
    //test(merge_sort, A, N);

    return 0;
}
void print(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t", A[i]);
    printf("\n");
}
void test(void func(int *, int), int *A, int n)
{
    clock_t bt, et;
    double t;

    bt = clock();
    func(A, n);
    et = clock();
    print(A, n);
    t = (et - bt) / 1e6;
    printf("time=%fseconds\n", t);
}
