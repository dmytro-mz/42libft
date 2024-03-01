#include "libft.h"

char *ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
    char *res;
    unsigned int i;
    
    res = (char *)malloc(ft_strlen(s) * sizeof(char));
    i = 0;
    while (s[i])
    {
        res[i] = (*f)(i, s[i]);
        i++;
    }
    res[i] = 0;
    return (res);
}
