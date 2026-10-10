#include <stdio.h>


int ft_atoi(char *str)
{
    int num;

    num = 0;
    while(*str)
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}


int ft_strcmp(char *s1, char *s2)
{
    while(*s1)
    {
        if(*s1 != *s2)
            return 0;
        s1++;
        s2++;
    }
    if(*s2)
        return 0;
    return 1;
}


int char_is_num(char c)
{
    return c >= '0' && c <= '9';
}


int str_is_num(char *s)
{
    while(*s)
    {
        if (!char_is_num(*s))
            return 0;
        s++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    printf("%d", str_is_num(argv[1]));
}
