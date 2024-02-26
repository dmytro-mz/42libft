#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    unsigned char    uc_c;
    size_t  i;
    const char *  res;

    uc_c = (unsigned char)c;
    res = NULL;
    i = 0;
    while (s[i])
    {
        if (s[i] == uc_c)
            res = s + i;
        i++;
    }
    if (s[i] == uc_c)
        res = s + i;
    return ((char *)res);
}