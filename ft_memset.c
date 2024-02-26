#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    size_t          i;
    unsigned char   uc_c;

    uc_c = (unsigned char)c;
    i = 0;
    while (i < len)
    {
        ((char *)b)[i] = uc_c;
        i++;
    }
    return (b);
}