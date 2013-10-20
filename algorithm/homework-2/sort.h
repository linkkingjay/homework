void swap(char a[LEN], char b[LEN])
{
    char tmp[LEN];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}
int desc(char *a, char *b)
{
    return strcmp(a, b);
}
int asc(char *a, char *b)
{
    return strcmp(b, a);
}
