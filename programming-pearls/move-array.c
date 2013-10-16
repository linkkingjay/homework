/**
 * @file move-array.c
 * @synopsis  将一个n元一维向量向左翻转i个位置
 * @author linkkingjay
 * @version 1.0
 * @date 2013-10-16
 */
#include<stdio.h>
#include<string.h>

void reverse(char *S, int left, int right)
{
    int i, mid;
    char tmp;
    for (i = 0, mid = (left + right) / 2; i + left <= mid; i++) {
        tmp = S[i + left];
        S[i + left] =  S[right - i];
        S[right - i] = tmp;
    }
}
void move_array(char *S, int i, int n)
{
    i %= n;
    if (i == 0)
        return;
    reverse(S, 0, i - 1);
    reverse(S, i, n - 1);
    reverse(S, 0, n - 1);
}
int main()
{
    int i, n;
    char s[100];
    scanf("%s", s);
    scanf("%d", &i);
    n = strlen(s);
    move_array(s, i, n);
    printf("%s\n", s);
    return 0;
}
