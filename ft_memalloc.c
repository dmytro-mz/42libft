#include "libft.h"

void    *ft_memalloc(size_t size)
{
    void *res;
    
    res = malloc(size);
    ft_bzero(res, size);
    return (res);
}