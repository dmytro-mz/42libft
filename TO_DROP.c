#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c))
		return (1);
	else if (ft_isdigit(c))
		return (1);
	return (0);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		dir;
	size_t	i;

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

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc_c;

	uc_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = uc_c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

size_t	ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 0 && src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = 0;
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	i = 0;
	while (i + dst_len < size && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < size)
		dst[dst_len + i] = 0;
	return (dst_len + ft_strlen(src));
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	const char		*res;

	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			res = s + i;
		i++;
	}
	if (s[i] == c)
		res = s + i;
	return ((char *)res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc_c;
	size_t			i;

	uc_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == uc_c)
			return (((unsigned char *)s) + i);
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s_s1;
	const char	*s_s2;

	if (n == 0)
		return (0);
	s_s1 = (const char *)s1;
	s_s2 = (const char *)s2;
	i = 0;
	while (s_s1[i] == s_s2[i] && i < n - 1)
		i++;
	return (s_s1[i] - s_s2[i]);
}

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

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

static int	ft_isspace(int c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*res;

	if (!nmemb || !size)
		return (NULL);
	if (nmemb > 2147483647 || size > 2147483647 / nmemb)
		return (NULL);
	total_size = nmemb * size;
	res = malloc(total_size);
	if (!res)
		return (NULL);
	ft_bzero(res, total_size);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

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

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *res;
    
    i = 0;
    while (s[i] && i <= start)
        i++;
    if (i <= start)
        return (NULL);
    i--;
    while (s[i] && i < start + len)
        i++;
    res = ft_calloc(i - start + 1, sizeof(char));
    if (!res)
        return (NULL);
    ft_memcpy(res, s + start, i - start);
    return (res);
}

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

char *ft_strtrim(char const *s1, char const *set)
{
    size_t i;
    size_t start;
    size_t end;
    char *res;

    if (!s1 || !set)
        return (NULL);
    if (s1[0] == 0 || set[0] == 0)
        return (ft_strdup(s1));
    i = 0;
    while (s1[i] && ft_strchr(set, s1[i]))
        i++;
    if (s1[i] == 0)
        return ((char *)ft_calloc(1, 1));
    start = i;
    end = i;
    while (s1[++i])
        if (!ft_strchr(set, s1[i]))
            end = i;
    res = (char *)malloc(sizeof(char) * (end - start + 2));
    ft_memcpy(res, s1 + start, end - start + 1);
    res[end - start + 2] = 0;
    return (res);
}

static int	word_count(char const *s, char sep)
{
	int count;
	int in_word;
	
	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != sep && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == sep)
			in_word = 0;
		s++;
	}
	return (count);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	return (res);
}


char	**ft_split(char const *s, char c)
{
	int		w;
	int		words;
	char	**res;
	const char *start;
	
	words = word_count(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	w = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			res[w++] = ft_strndup(start, s - start);
		}
		else
			s++;
	}
	res[w] = NULL;
	return (res);
}