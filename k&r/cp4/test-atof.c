#include <stdio.h>

double atof(char s[]);
int main()
{
    char *a = "123.456";
    printf("%f\n", atof(a));
    
    return 0;
}
