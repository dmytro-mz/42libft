#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    unsigned char    uc_c;
    size_t  i;

    uc_c = (unsigned char)c;
    i = 0;
    while (s[i])
    {
        if (s[i] == uc_c)
            return (char *)(s + i);
        i++;
    }
    if (s[i] == uc_c)
        return (char *)(s + i);
    return (NULL);
}