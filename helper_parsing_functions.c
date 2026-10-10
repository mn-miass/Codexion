#include <stdio.h>


int ft_atoi(char *str)
{
    int num;
    int sign;

    num = 0;
    sign = 1;
    while(*str == '-' && *str == '+')
    {
        if(*str == '-')
            sign = -1;
        str++;
    }
    while(*str)
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num * sign;
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
    while(*s && (*s == '+'))
        s++;
    if (!*s)
        return 0;
    while(*s)
    {
        if (!char_is_num(*s))
            return 0;
        s++;
    }
    return 1;
}


int ft_strlen(char *s)
{
    int count;

    count = 0;
    while(*s)
    {
        s++;
        count++;
    }
    return count;
}
