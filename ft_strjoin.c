#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t s1_len;
    size_t s2_len;
    char *res;
    
    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
    if (!res)
        return (NULL);
    ft_memcpy(res, s1, s1_len);
    ft_memcpy(res + s1_len, s2, s2_len);
    res[s1_len + s2_len] = 0;
    return (res);
}