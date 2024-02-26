#include "libft.h"

size_t ft_strlen(const char *s)
{
    size_t size;
    
    size = 0;
    while (s[size])
        size++;
    return (size);
}

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

char    *fn_strcpy(char *dst, const char *src)
{
    size_t i;
    
    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return (dst);
}

char    *ft_strncpy(char *dst, const char *src, size_t len)
{
    size_t i;
    
    i = 0;
    while (src[i] && i < len)
    {
        dst[i] = src[i];
        i++;
    }
    while (i < len)
    {
        dst[i] = 0;
        i++;
    }
    return (dst);
}

char    *ft_strncat(char *s1, const char *s2, size_t n)
{
    size_t s1_i;
    size_t s2_i;
    
    s1_i = ft_strlen(s1);
    s2_i = 0;
    while (s2[s2_i] && s2_i < n)
    {
        s1[s1_i + s2_i] = s2[s2_i];
        s2_i++;
    }
    s1[s1_i + s2_i] = 0;
    return (s1);
}

char    *ft_strcat(char *s1, const char *s2)
{
    return ft_strncat(s1, s2, ft_strlen(s2));
}

size_t  ft_strlcat(char * dst, const char *src, size_t dstsize)
{
    size_t  dst_len;
    
    dst_len = ft_strlen(dst);
    if (dstsize - dst_len - 1 > 0)
        ft_strncat(dst, src, dstsize - dst_len - 1);
    return (dst_len + ft_strlen(src));
}

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

char    *ft_strstr(const char *str, const char *sub)
{
    return (ft_strnstr(str, sub, ft_strlen(str)));
}

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

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    if (n == 0)
        return (0);
    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
        i++;
    return (s1[i] - s2[i]);
}

int ft_strcmp(const char *s1, const char *s2)
{
    return (ft_strncmp(s1, s2, ft_strlen(s1)));
}

int ft_atoi(const char *str)
{
    int sign;
    int res;
    
    while (ft_isspace(*str))
        str++;
    sign = 1;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    res = 0;
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*(str++) - '0') * sign;
    }
    return (res);
}

void    *ft_memset(void *b, int c, size_t len)
{
    size_t              i;
    unsigned char       uc_c;

    uc_c = (unsigned char)c;
    i = 0;
    while (i < len)
    {
        ((char *)b)[i] = uc_c;
        i++;
    }
    return (b);
}

void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        ((char *)dst)[i] = ((char *)src)[i];
        i++;
    }
    return (dst);
}

void    *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    size_t  i;
    unsigned char   uc_c;

    uc_c = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        ((char *)dst)[i] = ((char *)src)[i];
        if (((char *)src)[i] == uc_c)
            return (((char *)dst) + i + 1);
        i++;
    }
    return (NULL);
}

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    int     dir;
    size_t  i;
    
    dir = 1;
    i = 0;
    if (dst > src)
    {
        dir = -1;
        i = len - 1;
    }
    while (i < len)
    {
        ((char *)dst)[i] = ((char *)src)[i];
        if (i == 0 && dir == -1)
            break ;
        i += dir;
    }
    return (dst);
}

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char    uc_c;
    size_t  i;

    uc_c = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        if (((char *)s)[i] == uc_c)
            return (((char *)s) + i);
        i++;
    }
    return (NULL);
}

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