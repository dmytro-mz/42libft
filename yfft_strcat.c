#include "libft.h"

char    *ft_strcat(char *s1, const char *s2)
{
    return ft_strncat(s1, s2, ft_strlen(s2));
}