#include<stdio.h>
#include<string.h>
#include<time.h>

#define LEN 30
#define MAX 202

#include"sort.h"
#include"BubbleSort.c"
#include"SelectSort.c"

int main(int argc, char ** argv)
{
    int (*cmp)(char *, char *);
    void (*sort)(char [][30], int, int (*)());
    void error(char *);
    int i, n = 0;
    int order;
    char array[MAX + 1][LEN], tmp[LEN];

    // 输入输出文件
    FILE * iFile;
    FILE * oFile;

    // 开始时间bt和结束时间et
    clock_t bt, et;

    // 输入参数处理
    // 选择排序算法
    if (argc > 1) {
        if (strcmp(argv[1], "b") == 0) {
            sort = bubble_sort;
        } else if (strcmp(argv[1], "s") == 0) {
            sort = select_sort;
        } else {
            error("sort function name error!");
            return 0;
        }
    } else {
        sort = bubble_sort;
    }

    // 选择输入文件
    if (argc > 2) {
        iFile = fopen(argv[2], "r");
    } else {
        iFile = fopen("input.txt", "r");
    }
    if (iFile == NULL) {
        error("input file error!");
        return 0;
    }

    // 选择输出文件
    if (argc > 3) {
        oFile = fopen(argv[3], "w");
    } else {
        oFile = fopen("output.txt", "w");
    }

    // 选择排序方式
    if (argc > 4) {
        order = argv[4][0] - '0';
    } else {
        order = 0;
    }

    // 根据order的值指定比较函数
    if (order == 0) {
        cmp = asc;
    } else {
        cmp = desc;
    }

    // 从文件读取数据
    while (fscanf(iFile, "%s", tmp) != EOF) {
        strcpy(array[n], tmp);
        n++;
    }

    // 排序并计时
    bt = clock();
    bubble_sort(array, n, cmp);
    et = clock();
    

    // 输出数据到文件中去，输出排序所用时间
    for (i = 0; i < n; i++) {
        fprintf(oFile, "%s\n", array[i]);
    }
    printf("sorted successful.\n");
    printf("total time: %.fms\n", (double)(et - bt));
    return 0;
}
void error(char *msg) {
    printf("%s\n", msg);
}
