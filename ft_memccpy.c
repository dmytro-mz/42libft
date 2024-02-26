#include "libft.h"

void    *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    size_t  i;
    unsigned char   uc_c;

    uc_c = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        ((char *)dst)[i] = ((char *)src)[i];
        if (((char *)src)[i] == uc_c)
            return (((char *)dst) + i + 1);
        i++;
    }
    return (NULL);
}