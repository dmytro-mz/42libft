#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char    uc_c;
    size_t  i;

    uc_c = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        if (((char *)s)[i] == uc_c)
            return (((char *)s) + i);
        i++;
    }
    return (NULL);
}