#include <stdio.h>
#include "libft.h"
#include <ctype.h>

void test_ftstrlen(const char **test_strings)
{
    for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
        const char *test_str = *ptr;

        // Calculate lengths using both functions
        size_t ft_len = ft_strlen(test_str);
        size_t strlen_len = strlen(test_str);

        // Compare the results and print error message if lengths don't match
        if (ft_len != strlen_len) {
            printf("Error: Lengths don't match for string: \"%s\"\n", test_str);
        }
    }
}

void test_ftstrdup(const char **test_strings)
{
    for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
        const char *test_str = *ptr;

        // Duplicate string using both functions
        char *ft_dup = ft_strdup(test_str);
        char *strdup_dup = strdup(test_str);

        // Check if the duplicated strings are NULL
        if (ft_dup == NULL || strdup_dup == NULL) {
            printf("Error: Memory allocation failed for string: \"%s\"\n", test_str);
        } else {
            // Compare the duplicated strings
            if (strcmp(ft_dup, strdup_dup) != 0) {
                printf("Error: Duplicated strings don't match for string: \"%s\"\n", test_str);
            }
        }

        // Free the duplicated strings
        free(ft_dup);
        free(strdup_dup);
    }
}

void test_fn_strcpy(const char **test_strings) {
    for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
        const char *test_str = *ptr;

        // Prepare destination buffers for both functions
        char dst_buffer_fn[strlen(test_str) + 1]; // Allocate enough space for the string including the null terminator
        char dst_buffer_strcpy[strlen(test_str) + 1]; // Allocate enough space for the string including the null terminator

        // Copy the string using both functions
        char *fn_strcpy_result = fn_strcpy(dst_buffer_fn, test_str);
        char *strcpy_result = strcpy(dst_buffer_strcpy, test_str);

        // Check if the returned pointers point to the same location
        if (fn_strcpy_result != dst_buffer_fn) {
            printf("Error: Pointer returned by fn_strcpy don't match for string: \"%s\"\n", test_str);
        }
        if (strcpy_result != dst_buffer_strcpy) {
            printf("Error: Pointer returned by strcpy don't match for string: \"%s\"\n", test_str);
            printf("%p\n", strcpy_result);
            printf("%p\n", dst_buffer_strcpy);
        }

        // Check if the strings are equal
        if (strcmp(dst_buffer_fn, dst_buffer_strcpy) != 0) {
            printf("Error: Strings don't match after copying for string: \"%s\"\n", test_str);
        }
        if (strcmp(fn_strcpy_result, strcpy_result) != 0) {
            printf("Error: Strings don't match after copying for string: \"%s\", \"%s\", \"%s\"\n", test_str, fn_strcpy_result, strcpy_result);
        }
    }
}

void test_ft_strncpy(const char **test_strings, size_t max_len) {
    for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
        const char *test_str = *ptr;

        // Prepare destination buffers for both functions
        char dst_buffer_ft[strlen(test_str) + 1]; // Allocate enough space for the string including the null terminator
        char dst_buffer_strncpy[strlen(test_str) + 1]; // Allocate enough space for the string including the null terminator

        // Copy the string using both functions
        char *ft_strncpy_result = ft_strncpy(dst_buffer_ft, test_str, max_len);
        char *strncpy_result = strncpy(dst_buffer_strncpy, test_str, max_len);

        // Check if the returned pointers point to the same location
        if (ft_strncpy_result != dst_buffer_ft || strncpy_result != dst_buffer_strncpy) {
            printf("Error: Pointers returned by ft_strncpy and strncpy don't match for string: \"%s\"\n", test_str);
        }

        // Check if the strings are equal
        if (strncmp(dst_buffer_ft, dst_buffer_strncpy, max_len) != 0) {
            printf("Error: Strings don't match after copying for string: \"%s\"\n", test_str);
        }
    }
}

void test_ft_strcat(const char **test_strings) {
    for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
        const char *test_str1 = *ptr;
        
        // Find the length of the first string
        size_t len1 = strlen(test_str1);
        
        // Allocate memory for the destination buffer
        char dst_buffer_ft[len1 + 1 + 100]; // Allocate enough space for both strings and extra characters for safety
        char dst_buffer_strcat[len1 + 1 + 100];

        // Copy the first string into the destination buffer
        strcpy(dst_buffer_ft, test_str1);
        strcpy(dst_buffer_strcat, test_str1);

        // Call ft_strcat and strcat to concatenate the second string
        ft_strcat(dst_buffer_ft, " concatenate");
        strcat(dst_buffer_strcat, " concatenate");

        // Compare the result of ft_strcat with strcat
        if (strcmp(dst_buffer_ft, dst_buffer_strcat) != 0) {
            printf("Error: Result of ft_strcat does not match strcat for string: \"%s\"\n", test_str1);
        }
    }
}

void test_ft_strncat(const char **test_strings, size_t n) {
    for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
        const char *test_str1 = *ptr;

        // Find the length of the first string
        size_t len1 = strlen(test_str1);
        
        // Allocate memory for the destination buffer
        char dst_buffer_ft[len1 + 1 + 100]; // Allocate enough space for both strings and extra characters for safety
        char dst_buffer_strncat[len1 + 1 + 100];

        // Copy the first string into the destination buffer
        strcpy(dst_buffer_ft, test_str1);
        strcpy(dst_buffer_strncat, test_str1);

        // Call ft_strncat and strncat to concatenate the second string
        ft_strncat(dst_buffer_ft, " concatenate", n);
        strncat(dst_buffer_strncat, " concatenate", n);

        // Compare the result of ft_strncat with strncat
        if (strcmp(dst_buffer_ft, dst_buffer_strncat) != 0) {
            printf("Error: Result of ft_strncat does not match strncat for string: \"%s\"\n", test_str1);
        }
    }
}

// from https://stackoverflow.com/questions/18547251/when-i-use-strlcpy-function-in-c-the-compilor-give-me-an-error
size_t strlcat(char *dst, const char *src, size_t     size)
{
  size_t    srclen;         /* Length of source string */
  size_t    dstlen;         /* Length of destination string */


 /*
  * Figure out how much room is left...
  */

  dstlen = strlen(dst);
  size   -= dstlen + 1;

  if (!size)
    return (dstlen);        /* No room, return immediately... */

 /*
  * Figure out how much room is needed...
  */

  srclen = strlen(src);

 /*
  * Copy the appropriate amount...
  */

  if (srclen > size)
    srclen = size;

  memcpy(dst + dstlen, src, srclen);
  dst[dstlen + srclen] = '\0';

  return (dstlen + srclen);
}

void test_ft_strlcat(const char **test_strings, size_t dstsize) {
    for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
        const char *test_str1 = *ptr;

        // Allocate memory for the destination buffer
        char dst_buffer_ft[dstsize + 100]; // Allocate enough space for the destination buffer and extra characters for safety
        char dst_buffer_strlcat[dstsize + 100];

        // Copy the first string into the destination buffer
        strcpy(dst_buffer_ft, test_str1);
        strcpy(dst_buffer_strlcat, test_str1);

        // Call ft_strlcat and strlcat to concatenate the second string
        ft_strlcat(dst_buffer_ft, " concatenate", dstsize);
        strlcat(dst_buffer_strlcat, " concatenate", dstsize);

        // Compare the result of ft_strlcat with strlcat
        if (strcmp(dst_buffer_ft, dst_buffer_strlcat) != 0) {
            printf("Error: Result of ft_strlcat does not match strlcat for string: \"%s\"\n", test_str1);
        }
    }
}

void test_ft_strchr(const char **test_strings, int c) {
    for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
        const char *test_str = *ptr;

        // Call ft_strchr and strchr to find the first occurrence of character c
        char *ft_strchr_result = ft_strchr(test_str, c);
        char *strchr_result = strchr(test_str, c);

        // Compare the result of ft_strchr with strchr
        if (ft_strchr_result != strchr_result) {
            printf("Error: Result of ft_strchr does not match strchr for string: \"%s\"\n", test_str);
        }
    }
}

void test_ft_strrchr(const char **test_strings, int c) {
    for (const char **ptr = test_strings; *ptr != NULL; ++ptr) {
        const char *test_str = *ptr;

        // Call ft_strrchr and strrchr to find the last occurrence of character c
        char *ft_strrchr_result = ft_strrchr(test_str, c);
        char *strrchr_result = strrchr(test_str, c);

        // Compare the result of ft_strrchr with strrchr
        if (ft_strrchr_result != strrchr_result) {
            printf("Error: Result of ft_strrchr does not match strrchr for string: \"%s\"\n", test_str);
        }
    }
}

void test_ft_strstr(const char *str, const char *sub) {
    // Call ft_strstr and strstr to find the substring sub in str
    char *ft_strstr_result = ft_strstr(str, sub);
    char *strstr_result = strstr(str, sub);

    // Compare the result of ft_strstr with strstr
    if ((ft_strstr_result == NULL && strstr_result != NULL) || (ft_strstr_result != NULL && strstr_result == NULL) ||
        (ft_strstr_result != NULL && strstr_result != NULL && strcmp(ft_strstr_result, strstr_result) != 0)) {
        printf("Error: Result of ft_strstr does not match strstr for string: \"%s\" and substring: \"%s\"\n", str, sub);
    }
}

// from https://stackoverflow.com/questions/23999797/implementing-strnstr
char *strnstr(const char *haystack, const char *needle, size_t len)
{
        int i;
        size_t needle_len;

        if (0 == (needle_len = strnlen(needle, len)))
                return (char *)haystack;

        for (i=0; i<=(int)(len-needle_len); i++)
        {
                if ((haystack[0] == needle[0]) &&
                        (0 == strncmp(haystack, needle, needle_len)))
                        return (char *)haystack;

                haystack++;
        }
        return NULL;
}

void test_ft_strnstr(const char *str, const char *sub, size_t len) {
    // Call ft_strnstr and strnstr to find the substring sub in str up to len characters
    char *ft_strnstr_result = ft_strnstr(str, sub, len);
    char *strnstr_result = strnstr(str, sub, len);

    // Compare the result of ft_strnstr with strnstr
    if ((ft_strnstr_result == NULL && strnstr_result != NULL) || (ft_strnstr_result != NULL && strnstr_result == NULL) ||
        (ft_strnstr_result != NULL && strnstr_result != NULL && strcmp(ft_strnstr_result, strnstr_result) != 0)) {
        printf("Error: Result of ft_strnstr does not match strnstr for string: \"%s\", substring: \"%s\", and length: %zu\n", str, sub, len);
    }
}

void test_ft_strcmp(const char *s1, const char *s2) {
    // Call ft_strcmp and strcmp to compare the strings s1 and s2
    int ft_strcmp_result = ft_strcmp(s1, s2);
    int strcmp_result = strcmp(s1, s2);

    // Compare the result of ft_strcmp with strcmp
    if (ft_strcmp_result != strcmp_result) {
        printf("Error: Result of ft_strcmp does not match strcmp for strings: \"%s\" and \"%s\"\n", s1, s2);
    }
}

void test_ft_strncmp(const char *s1, const char *s2, size_t n) {
    // Call ft_strncmp and strncmp to compare the strings s1 and s2 for the first n characters
    int ft_strncmp_result = ft_strncmp(s1, s2, n);
    int strncmp_result = strncmp(s1, s2, n);

    // Compare the result of ft_strncmp with strncmp
    if (ft_strncmp_result != strncmp_result) {
        printf("Error: Result of ft_strncmp does not match strncmp for strings: \"%s\" and \"%s\" with length: %zu\n", s1, s2, n);
    }
}

void test_ft_memcpy(const void *src, size_t n) {
    char dst_ft[20] = {0};
    char dst_memcpy[20] = {0};
    
    void *ft_memcpy_result = ft_memcpy(dst_ft, src, n);
    memcpy(dst_memcpy, src, n);
    
    if (dst_ft != ft_memcpy_result) {
        printf("Error: Result of ft_memcpy returns wrong value\n");
    }
    if (memcmp(dst_ft, dst_memcpy, n) != 0) {
        printf("Error: Result of ft_memcpy does not match memcpy for %zu bytes\n", n);
    }
}

void test_ft_memccpy(const void *src, int c, size_t n) {
    char dst_ft[100] = {0};
    char dst_memccpy[100] = {0};
    
    void *ft_memccpy_result = ft_memccpy(dst_ft, src, c, n);
    void *memccpy_result = memccpy(dst_memccpy, src, c, n);
    
    if ((ft_memccpy_result == NULL && memccpy_result != NULL) || (ft_memccpy_result != NULL && memccpy_result == NULL) ||
        (ft_memccpy_result != NULL && memccpy_result != NULL && *(char *)ft_memccpy_result != *(char *)memccpy_result)) {
        printf("Error: Result of ft_memccpy does not match memccpy for %zu bytes\n", n);
    }
}

void test_ft_memmove(void *dst_ft, void *src_ft, size_t len) {
    char *dst_memmove = ft_strdup(dst_ft);
    char *src_memmove = ft_strdup(src_ft);
    char *ft_memmove_result = (char *)ft_memmove(dst_ft, src_ft, len);
    char *memmove_result = (char *)memmove(dst_memmove, src_memmove, len);
    
    if (dst_ft != ft_memmove_result) {
        printf("Error: Result of ft_memmove returns wrong value\n");
    }
    if (strcmp((char *)ft_memmove_result, (char *)memmove_result) != 0) {
        printf("Error: Result of ft_memmove does not match memmove: %ld\n", src_ft - dst_ft);
    }
    free(dst_memmove);
    free(src_memmove);
}

void test_ft_memchr(const void *s, int c, size_t n) {
    void *ft_memchr_result = ft_memchr(s, c, n);
    void *memchr_result = memchr(s, c, n);

    if (ft_memchr_result != memchr_result) {
        printf("Error: Result of ft_memchr does not match memchr\n");
    }
}

void test_ft_memcmp(const void *s1, const void *s2, size_t n) {
    // Call ft_memcmp and memcmp to compare the strings s1 and s2 for the first n characters
    int ft_memcmp_result = ft_memcmp(s1, s2, n);
    int memcmp_result = memcmp(s1, s2, n);

    // Compare the result of ft_memcmp with memcmp
    if (ft_memcmp_result != memcmp_result) {
        printf("Error: Result of ft_memcmp does not match memcmp for strings: \"%s\" and \"%s\" with length: %zu\n", (char *)s1, (char *)s2, n);
    }
}

int main()
{
    // // TEST SINGLE CHAR FUNCTIONS
    for (int i = -1; i <= 128; i++) {
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

        if (toupper(i) != ft_toupper(i))
            printf("Error in toupper(%d)\n", i);

        if (tolower(i) != ft_tolower(i))
            printf("Error in tolower(%d)\n", i);

        if (!!isspace(i) != !!ft_isspace(i))
            printf("Error in isspace(%d)\n", i);
    }
    
    // // TEST STR FUNCTIONS
    {
        const char *test_strings[] = {
            "Hello, world!",
            "This is a test string.",
            "An empty string.",
            "",
            "12345",
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
            NULL // End of test strings marker
        };
        
        // ft_strlen
        test_ftstrlen(test_strings);
        // ft_strdup
        test_ftstrdup(test_strings);
        // fn_strcpy
        test_fn_strcpy(test_strings);
        // ft_strncpy
        test_ft_strncpy(test_strings, 10);
        // ft_strcat
        test_ft_strcat(test_strings);
        // ft_strncat
        test_ft_strncat(test_strings, 5);
        // ft_strlcat
        test_ft_strncat(test_strings, 15);
        // ft_strchr
        test_ft_strchr(test_strings, 'r');
        test_ft_strchr(test_strings, 't');
        // ft_strrchr
        test_ft_strrchr(test_strings, 'r');
        test_ft_strrchr(test_strings, 't');
        // ft_strstr
        const char *str = "This is a test string.";
        const char *sub1 = "is";
        const char *sub2 = "Hello";
        const char *sub3 = "string";
        const char *sub4 = "";
        {
            test_ft_strstr(str, sub1);
            test_ft_strstr(str, sub2);
            test_ft_strstr(str, sub3);
            test_ft_strstr(str, sub4);
        }
        // ft_strnstr
        {
            test_ft_strnstr(str, sub1, 15);
            test_ft_strnstr(str, sub2, 15);
            test_ft_strnstr(str, sub3, 15);
            test_ft_strnstr(str, sub4, 15);
        }
        // ft_strcmp
        {
            const char *s1 = "Hello";
            const char *s2 = "Hello";
            const char *s3 = "World";
            const char *s4 = "Goodbye";
            const char *s5 = "";
            test_ft_strcmp(s1, s2);
            test_ft_strcmp(s1, s3);
            test_ft_strcmp(s1, s4);
            test_ft_strcmp(s1, s5);
        }
        // ft_strncmp
        {
            const char *s1 = "Hello";
            const char *s2 = "Hello";
            const char *s3 = "World";
            const char *s4 = "Hello!";
            size_t n = 5;
            test_ft_strncmp(s1, s2, n);
            test_ft_strncmp(s1, s3, n);
            test_ft_strncmp(s1, s3, 0);
            test_ft_strncmp(s1, s4, n);
        }
        // ft_atoi
        const char *test_atoi_strings[] = {
            "1",
            "7",
            "10",
            "100000",
            "946189",
            "-1",
            "-7",
            "-10",
            "-100000",
            "-946189",
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
            "  +01ad",
            " \t\n\v\r\f -1",
            "asdasd -5",
            "++5",
            "--9",
            "- 9",
            "",
            NULL // End of test strings marker
        };
        int i = -1;
        while (test_atoi_strings[++i])
        {
            if (atoi(test_atoi_strings[i]) != ft_atoi(test_atoi_strings[i]))
                printf("Error in atoi(%s): %d vs %d\n", test_atoi_strings[i], atoi(test_atoi_strings[i]), ft_atoi(test_atoi_strings[i]));
        }
        
    }
    // memset
    char str_memset[] = "99999999";
    ft_memset(str_memset, 'a', 5);
    if (strcmp(str_memset, "aaaaa999") != 0)
        printf("Error in ft_memset: %s\n", str_memset);
    // ft_bzero
    ft_bzero(str_memset, 2);
    if (str_memset[0] != 0 || str_memset[1] != 0 || str_memset[2] != 'a')
        printf("Error in ft_bzero: %s\n", str_memset);
    // ft_memcpy
    const char *str_memcpy = "Hello, world!";
    test_ft_memcpy(str_memcpy, strlen(str_memcpy) + 1);
    // ft_memccpy
    test_ft_memccpy(str_memcpy, 'o', strlen(str_memcpy) + 1);
    test_ft_memccpy(str_memcpy, '!', strlen(str_memcpy) + 1);
    test_ft_memccpy(str_memcpy, 0, strlen(str_memcpy) + 1);
    // ft_memmove
    char str_memmove[] = "0123456789";
    test_ft_memmove(str_memmove, str_memmove, 5);
    test_ft_memmove(str_memmove + 3, str_memmove, 5);
    test_ft_memmove(str_memmove, str_memmove + 3, 5);
    // ft_memchr
    for (size_t i = 0; i < strlen(str_memcpy); i++)
        test_ft_memchr(str_memcpy + i, 'o', strlen(str_memcpy) + 1 - i);
    // ft_memcmp
    {
        const char *s1 = "Hello";
        const char *s2 = "Hello";
        const char *s3 = "World";
        const char *s4 = "Hello!";
        size_t n = 5;
        test_ft_memcmp(s1, s2, n);
        test_ft_memcmp(s1, s3, n);
        test_ft_memcmp(s1, s3, 0);
        test_ft_memcmp(s1, s4, n);
    }
    // ft_memalloc
    {
        void *tmp = ft_memalloc(4);
        if (ft_memcmp(tmp, "\0\0\0", 4) != 0)
            printf("Error in ft_memcmp");
    }
    
    printf("END");

    return 0;
}
