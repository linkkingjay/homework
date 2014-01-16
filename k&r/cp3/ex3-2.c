#include <stdio.h>

void escape(char *s, char *t) {
    int i, j;
    for (i = j = 0; s[i]; i++) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j] = '\0';
}
int main()
{
    char t[100];
    char *s = "hello, world\n1\t2\t3\t";
    escape(s, t);

    printf("s:\n%s\n\n", s);
    printf("t:\n%s\n", t);

    return 0;
}
