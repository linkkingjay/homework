#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void error(char *);
int simple_search(char *, char *);
int main(int argc, char **argv)
{
    char *string;
    char *keyword;
    FILE *iFile;

    // 选择输入文件
    if (argc > 1) {
        iFile = fopen(argv[1], "r");
    } else {
        iFile = fopen("yingwen.txt", "r");
    }
    if (iFile == NULL) {
        error("input file error!");
        return 0;
    }

    // 选择要查找的字符串
    if (argc > 2) {
        keyword = (char *)malloc(sizeof(char) * strlen(argv[2]));
        strcpy(keyword, argv[2]);
    } else {
        error("no keyword!");
        return 0;
    }

    // 输入字符串
    string = (char *)malloc(sizeof(*iFile));
    fscanf(iFile, "%s", string);

    // 输出结果
    printf("%d\n", simple_search(string, keyword));

    return 0;
}
// 蛮力法搜索字符串
int simple_search(char *string, char *keyword)
{
    int i, j;
    for (i = 0; string[i]; i++) {
        for (j = 0; keyword[j]; j++) {
            if (string[i + j] != keyword[j]) {
                break;
            }
        }
        if (!keyword[j]) {
            return i;
        }
    }
    return -1;
}

// 错误信息
void error(char *msg)
{
    printf("%s\n", msg);
}
