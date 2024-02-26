#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    const char *s_s1;
    const char *s_s2;
    
    if (n == 0)
        return (0);
    s_s1 = (const char *)s1;
    s_s2 = (const char *)s2;
    i = 0;
    while (s_s1[i] == s_s2[i] && i < n - 1)
        i++;
    return (s_s1[i] - s_s2[i]);
}