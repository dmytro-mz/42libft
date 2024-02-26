#include "libft.h"

char    *ft_strnstr(const char *str, const char *sub, size_t len)
{
    size_t i;
    size_t j;

    if (!sub[0])
        return ((char *)str);
    i = 0;
    j = 0;
    while (str[i] && i < len)
    {
        if (str[i] != sub[j])
            j = 0;
        if (str[i] == sub[j])
        {
            j++;
            if (!sub[j])
                return ((char *)(str + i - j + 1));
        }
        i++;
    }
    return (NULL);
}