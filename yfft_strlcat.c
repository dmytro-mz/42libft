#include "libft.h"

size_t  ft_strlcat(char * dst, const char *src, size_t dstsize)
{
    size_t  dst_len;
    
    dst_len = ft_strlen(dst);
    if (dstsize - dst_len - 1 > 0)
        ft_strncat(dst, src, dstsize - dst_len - 1);
    return (dst_len + ft_strlen(src));
}