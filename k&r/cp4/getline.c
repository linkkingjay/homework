#include <stdio.h>
/**
 * @file getline.c
 * @synopsis  get line into s, return length
 * @author linkkingjay
 * @version 1
 * @date 2014-01-05
 */
int getLine(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

