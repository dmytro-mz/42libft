#include "libft.h"

int ft_isalpha(int c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    else if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_isalnum(int c)
{
    if (ft_isalpha(c))
        return (1);
    else if (ft_isdigit(c))
        return (1);
    return (0);
}

int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0);
}

int ft_isprint(int c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (0);
}

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

int ft_isspace(int c)
{
    if (c >= 9 && c <= 13)
        return (1);
    else if (c == ' ')
        return (1);
    return (0);
}