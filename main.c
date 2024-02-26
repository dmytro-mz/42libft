#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void	test_is_funcs(void)
{
	for (int i = -1; i <= 128; i++)
	{
		if ((!!isalpha(i) != !!ft_isalpha(i)))
			printf("Error in isalpha(%d)\n", i);
		if ((!!isdigit(i) != !!ft_isdigit(i)))
			printf("Error in isdigit(%d)\n", i);
		if ((!!isalnum(i) != !!ft_isalnum(i)))
			printf("Error in isalnum(%d)\n", i);
		if ((!!isascii(i) != !!ft_isascii(i)))
			printf("Error in isascii(%d)\n", i);
		if ((!!isprint(i) != !!ft_isprint(i)))
			printf("Error in isprint(%d)\n", i);
	}
}

void	test_strlen(void)
{
	size_t		ft_len;
	size_t		strlen_len;
	const char	*test_strings[] = {
        "Hello, world!",
        "This is a test string.",
        "An empty string.", "", "12345",
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
        NULL
    };

	for (const char **ptr = test_strings; *ptr != NULL; ++ptr)
	{
        const char *test_str = *ptr;
		ft_len = ft_strlen(test_str);
		strlen_len = strlen(test_str);
		if (ft_len != strlen_len)
		{
			printf("Error: Lengths don't match for string: \"%s\"\n", test_str);
		}
	}
}

void	test_memset(void)
{
	char	str_ftmemset[] = "123456789";
	char	*str_memset;
	size_t	str_size;

	str_memset = strdup(str_ftmemset);
	str_size = strlen(str_ftmemset);
	for (int i = -5; i < 1000; i++)
	{
		ft_memset(str_ftmemset, i, 5);
		memset(str_memset, i, 5);
		if (memcmp(str_memset, str_ftmemset, str_size) != 0)
		{
			printf("Error in ft_memset for char: %d\n", i);
			break ;
		}
	}
}

void	test_bzero(void)
{
	char	str_ftbzero[] = "123456789";
	char	*str_bzero;
	size_t	str_size;

	str_bzero = strdup(str_ftbzero);
	str_size = strlen(str_ftbzero);
	ft_bzero(str_ftbzero, 5);
	bzero(str_bzero, 5);
	if (memcmp(str_bzero, str_ftbzero, str_size) != 0)
		printf("Error in ft_bzero\n");
    free(str_bzero);
}

void	test_memcpy()
{
    const char *str = "Hello, world!";
    size_t n = strlen(str) + 1;
	char	dst_ft[20] = {0};
	char	dst_memcpy[20] = {0};
	
    void *ft_memcpy_result = ft_memcpy(dst_ft, str, n);
	memcpy(dst_memcpy, str, n);
	if (dst_ft != ft_memcpy_result)
	{
		printf("Error: Result of ft_memcpy returns wrong value\n");
	}
	if (memcmp(dst_ft, dst_memcpy, n) != 0)
	{
		printf("Error: Result of ft_memcpy does not match memcpy for %zu bytes\n", n);
	}
}

void	test_memmove(void)
{
	void	inner(void *dst_ft, void *src_ft, size_t len)
	{
		char *dst_memmove = strdup(dst_ft);
		char *src_memmove = strdup(src_ft);
		char *ft_memmove_result = (char *)ft_memmove(dst_ft, src_ft, len);
		char *memmove_result = (char *)memmove(dst_memmove, src_memmove, len);

		if (dst_ft != ft_memmove_result)
			printf("Error: Result of ft_memmove returns wrong value\n");
		if (strcmp(ft_memmove_result, memmove_result) != 0)
			printf("Error: Result of ft_memmove does not match memmove: %ld\n", src_ft - dst_ft);
		free(dst_memmove);
		free(src_memmove);
	}
	char str[] = "0123456789";
	inner(str, str, 5);
	inner(str + 3, str, 5);
	inner(str, str + 3, 5);
}

int	main(void)
{
	test_is_funcs();
	test_strlen();
	test_memset();
    test_bzero();
    test_memcpy();
	printf("END\n");
}
