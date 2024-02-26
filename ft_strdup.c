#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char *res;
    size_t i;
    
    res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
    if (!res)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    res[i] = 0;
    return (res);
}