#include "libft.h"

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
			res[w++] = ft_substr(start, 0, s - start);
		}
		else
			s++;
	}
	res[w] = NULL;
	return (res);
}