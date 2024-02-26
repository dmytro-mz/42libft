#include "libft.h"

char    *ft_strstr(const char *str, const char *sub)
{
    return (ft_strnstr(str, sub, ft_strlen(str)));
}