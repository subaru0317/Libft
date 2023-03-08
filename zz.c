/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:22:42 by takkatao          #+#    #+#             */
/*   Updated: 2023/03/08 15:50:01 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (len <= 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i] || i == len - 1)
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = dest;
	while (len--)
		*ptr++ = c;
	return (dest);
}

static size_t min(size_t x, size_t y)
{
	if (x > y)
		return (y);
	return (x);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	s_len;
	
	s_len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (min(len, s_len) + 1));
	if (!dst)
		return (NULL);
	if (start >= s_len || len == 0)
		return (ft_memset(dst, '\0', sizeof(char)));
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}

void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, 0, len);
	return ;
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size * number);
	if (!ptr)
		return (NULL);
	if (size != 0 && number * size / size != number)
		return (NULL);
	ft_bzero(ptr, size * number);
	return (ptr);
}

static int	cnt_substr_size(char const *s, char c)
{
	int	i;;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	cnt_substr(char const *s, char c)
{
	int		cnt;
	char	*ptr;

	cnt = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		while (*ptr == c)
			ptr++;
		if (*ptr == '\0')
			break;
		ptr += cnt_substr_size(ptr, c);
		cnt++;
	}
	return (cnt);
}

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_index;
	size_t 	little_len;

	little_len = ft_strlen(little);
	if (big == NULL || len < little_len)
		return (NULL);
	big_index = 0;
	if (*little) {
		while (ft_strncmp(big + big_index, little, little_len))
		{
			big_index++;
			len--;
			while (big[big_index] != *little)
			{
				if (big[big_index] == '\0' || len < 1)
					return (NULL);
				big_index++;
				len--;
			}
			if (len < little_len)
				return (NULL);
		}
	}
	return ((char *)(big + big_index));
}


char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		len;
	
	len = ft_strlen(str);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	ft_memmove(cpy, str, len);
	cpy[len] = '\0';
	return (cpy);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	ft_strlcpy(dst + i, src, dstsize - i);
	return (min(dstsize, dst_len) + src_len);
}

char	**ft_split(char const *s, char c)
{
	int		num_substr;
	int		i;
	int		j;
	int		substr_size;
	char	**arr;
	
	num_substr = cnt_substr(s, c);
	i = 0;
	j = 0;
	arr = (char **)ft_calloc(num_substr + 1, sizeof(char*));
	if (!arr)
		return (NULL);
	while (num_substr--)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		substr_size = cnt_substr_size(s + i, c);
		arr[j] = ft_substr(s, i, substr_size);
		if (!arr[j])
		{
			free(arr);
			return (NULL);
		}
		i += substr_size;
		j++;
	}
	return (arr);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	const char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (dst <= src)
	{
		while (len)
		{
			*dst_ptr++ = *src_ptr++;
			len--;
		}
	}
	else
	{
		dst_ptr += len - 1;
		src_ptr += len - 1;
		while (len)
		{
			*dst_ptr-- = *src_ptr--;
			len--;
		}
	}
	return (dst);
}


char	*ft_itoa(int n)
{
	int			len;
	long long	tmp;
	int			flag;
	int			i;
	char		*str;

	len = 0;
	flag = 0;
	tmp = n;
	if (tmp == 0)
	{
		str = (char *)ft_calloc(2, sizeof(char));
		if (!str)
			return (NULL);
		*str = '0';
		return (str);
	}
	if (tmp < 0)
	{
		len++;
		flag = 1;
		tmp *= -1;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (flag)
		str[i++] = '-';
	i = len;
	tmp = n;
	if (tmp < 0)
		tmp *= -1;
	while (i--)
	{
		if (flag && i == 0)
			break;
		str[i] = tmp % 10 + '0';
		tmp /= 10;	
	}
	return (str);
}

static int ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char		c;
	const char	*s;
	int			minus;
	long long		acc;

	s = nptr;
	c = *s++;
	while (ft_isspace((unsigned char)c))
		c = *s++;
	if (c == '-')
	{
		minus = 1;
		c = *s++;
	}
	else
	{
		minus = 0;
		if (c == '+')
			c = *s++;
	}
	acc = 0;
	while (1)
	{
		if ('0' <= c && c <= '9')
			c -= '0';
		else
			break ;
		acc *= 10;
		acc += c;
		c = *s++;
	}
	if (minus)
		acc *= -1;
	if (acc > LONG_MAX)
		return (LONG_MAX);
	if (acc < LONG_MIN)
		return (LONG_MIN);
	return (acc);
}

void	my_test_memmove(char *dest1, char *dest2,const char *src, size_t size)
{
	
	pid_t pid;
	pid_t wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;

	char*	expect;
	char*	actual;

	printf("====test(%s,%s,%s,%zu)\n",dest1, dest2, src, size);
	pid = fork();
	if (pid == 0)
	{
		memmove(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		ft_memmove(dest2, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_actual);
	}

	assert(WIFEXITED(status_expect) == WIFEXITED(status_actual));
	assert(WIFSIGNALED(status_expect) == WIFSIGNALED(status_actual));
	if (WIFEXITED(status_expect))
	{
		if (dest1 == NULL && dest2 == NULL)
		{
			printf("  Returned NULL \n");	
			assert(dest1 == dest2);
		}
		else
		{
			memmove(dest1, src, size);
			ft_memmove(dest2, src, size);
			printf("  %s：expect\n", dest1);
			printf("  %s：actual\n", dest2);
			assert(!strncmp(dest1, dest2, size));
		}
	}
	else
	{
		printf("  Sig Abort \n");
		printf("  WTERMSIG:%d\n",WTERMSIG(status_actual));
	}
	free(dest1);
	free(dest2);
}

int	testmain_memmove(void)
{
	char *dest1;
	char *dest2;
	const char *src = ft_strdup(" World");
	size_t	size = 6;

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_memmove(dest1, dest2, src, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_memmove(dest1, dest2, NULL, size);


	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_memmove(dest1, dest2, NULL, 1);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_memmove(dest1, dest2, NULL, 0);

	my_test_memmove(NULL, NULL, src, size);
	my_test_memmove(NULL, NULL, src, 1);
	my_test_memmove(NULL, NULL, src, 0);


	my_test_memmove(NULL, NULL, NULL, size);
	my_test_memmove(NULL, NULL, NULL, 1);
	my_test_memmove(NULL, NULL, NULL, 0);

	free(src);
	return(0);
}

#include <stdio.h>
#include <assert.h> 

void	my_test_atoi(const char *input)
{
	int a = ft_atoi(input);
	int b = atoi(input);
	
	printf("%s\n", input);
	printf("  %d：ft_atoi\n", a);
	printf("  %d：atoi\n", b);
	assert(a == b);
}

int	testmain_atoi(void)
{
	my_test_atoi("0");
	my_test_atoi("1");
	my_test_atoi("-1");
	my_test_atoi("8");
	my_test_atoi("127");
	my_test_atoi("128");
	my_test_atoi("129");

	my_test_atoi("254");
	my_test_atoi("255");
	my_test_atoi("256");

	my_test_atoi("2147483646");
	my_test_atoi("2147483647");//INT_MAX
	my_test_atoi("2147483648");

	my_test_atoi("4294967294");
	my_test_atoi("4294967295");//UNSIGNED INT_MAX
	my_test_atoi("4294967296");

	my_test_atoi("9223372036854775806");
	my_test_atoi("9223372036854775807");//LONG MAX
	my_test_atoi("9223372036854775808");

	my_test_atoi("18446744073709551614");
	my_test_atoi("18446744073709551615");//UNSIGNED LONG MAX
	my_test_atoi("18446744073709551616");

	my_test_atoi(" -2147483649");
	my_test_atoi(" -2147483648");//INT_MIN
	my_test_atoi(" -2147483647");

	my_test_atoi(" -9223372036854775809");
	my_test_atoi(" -9223372036854775808");//LONG NIN
	my_test_atoi(" -9223372036854775807");

	my_test_atoi(" -922337203685477580009");
	my_test_atoi(" -922337203685477580008");//LONG NIN
	my_test_atoi(" -922337203685477580007");

	my_test_atoi(" 634106827633765826700");
	my_test_atoi(" 63410682763376582680");
	my_test_atoi(" 63410682763376582678");
	my_test_atoi(" 922337203685477580008");
	my_test_atoi(" 922337203685477580007");

	my_test_atoi(" -634106827633765826700");
	my_test_atoi(" -63410682763376582679");
	my_test_atoi(" -63410682763376582680");
	my_test_atoi(" -63410682763376582678");
	my_test_atoi(" -922337203685477580008");
	my_test_atoi(" -922337203685477580007");

	my_test_atoi("9223372036854775812");
	my_test_atoi("922337203685477570");
	my_test_atoi("922337203685477577");

	my_test_atoi("-9223372036854775807");
	my_test_atoi("-9223372036854775807");
	my_test_atoi("9223372036854775806");
	my_test_atoi("9223372036854775806");

	my_test_atoi("-2147483649");
	my_test_atoi("-2147483649");
	my_test_atoi("2147483648");
	my_test_atoi("2147483648");

    my_test_atoi("-2147483658");
    my_test_atoi("-2147483658");
    my_test_atoi("2147483657");
    my_test_atoi("2147483657");

	my_test_atoi("9223372036854775808");
	my_test_atoi("9223372036854775808");
	my_test_atoi("92233720368547758000");
	my_test_atoi("92233720368547758000");
	my_test_atoi("-9223372036854775809");
	my_test_atoi("-9223372036854775809");
	my_test_atoi("-92233720368547758000");
	my_test_atoi("-92233720368547758000");
	
	my_test_atoi("4772185884");
	my_test_atoi("9544371768");
	my_test_atoi("14316557653");
	return (0);
}

#include <stdio.h>
#include <assert.h> 

void	my_test_itoa(long long input)
{
	char	*a = ft_itoa((int)input);
//	char	*b = itoa((int)input);

	printf("%lld(as lld)\n", input);
	printf("%d:(as int)\n", (int)input);
	printf("  %s：ft_atoi\n", a);
	assert((int)input == atoi(a));
	free(a);
}

int	testmain_itoa(void)
{
	my_test_itoa(0);
	my_test_itoa(1);
	my_test_itoa(-1);
	my_test_itoa(8);
	my_test_itoa(127);
	my_test_itoa(128);
	my_test_itoa(129);

	my_test_itoa(254);
	my_test_itoa(255);
	my_test_itoa(256);

	my_test_itoa(2147483646);
	my_test_itoa(2147483647);//INT_MAX
	my_test_itoa(2147483648);

	my_test_itoa(4294967294);
	my_test_itoa(4294967295);//UNSIGNED INT_MAX
	my_test_itoa(4294967296);

	my_test_itoa(9223372036854775806);
	my_test_itoa(9223372036854775807);//LONG MAX
	my_test_itoa(9223372036854775808);

	my_test_itoa(18446744073709551614);
	my_test_itoa(18446744073709551615);//UNSIGNED LONG MAX
//	my_test(18446744073709551616);

	my_test_itoa( -2147483649);
	my_test_itoa( -2147483648);//INT_MIN
	my_test_itoa( -2147483647);

	my_test_itoa( -9223372036854775809);
	my_test_itoa( -9223372036854775808);//LONG NIN
	my_test_itoa( -9223372036854775807);
	return (0);
}

#include <string.h>
#include <xlocale.h>
#include <stdio.h>
#include <assert.h> 

void	print_and_free(char **a)
{
	int		i;

	if (a != NULL)
	{
		i = 0;
		while (a[i] != NULL)
		{
			printf("  %s\n",a[i]);
			free(a[i++]);
		}
	}
	free(a);
	printf("  ---free completed---\n");

}

int	testmain_split(void)
{
	char	**a;

	a = ft_split("hello world", ' ');
	assert(!strcmp(a[0], "hello"));
	assert(!strcmp(a[1], "world"));
	print_and_free(a);

	a = ft_split("abcdaba", 'a');
	assert(!strcmp(a[0], "bcd"));
	assert(!strcmp(a[1], "b"));
	print_and_free(a);

	a = ft_split("abcdaba", '\0');
	assert(!strcmp(a[0], "abcdaba"));
	print_and_free(a);

	a = ft_split("", 'a');
	assert(*a == NULL);
	print_and_free(a);

	a = ft_split(NULL, 'a');
	assert(*a == NULL);
	print_and_free(a);

	a = ft_split("      ", ' ');
	assert(*a == NULL);
	print_and_free(a);

	a = ft_split("\0aa\0bbb", '\0');
	assert(*a == NULL);
	print_and_free(a);


	return (0);
}


#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 

void	my_test_strlcat(char *dest1, char *dest2,const char *src, size_t size)
{
	
	pid_t pid;
	pid_t wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;

	size_t	expect;
	size_t	actual;

	printf("====test(%s,%s,%s,%zu)\n",dest1, dest2, src, size);
	pid = fork();
	if (pid == 0)
	{
		expect = strlcat(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		actual = ft_strlcat(dest2, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_actual);
	}

	assert(WIFEXITED(status_expect) == WIFEXITED(status_actual));
	assert(WIFSIGNALED(status_expect) == WIFSIGNALED(status_actual));
	if (WIFEXITED(status_expect))
	{
		expect = strlcat(dest1, src, size);
		actual = ft_strlcat(dest2, src, size);
		printf("  %zu：expect\n", expect);
		printf("  %zu：actual\n", actual);
		assert(expect == actual);
	}
	else
	{
		printf(" Sig Abort \n");
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual));
	}
	free(dest1);
	free(dest2);
}

int	testmain_strlcat(void)
{

	char *dest1;
	char *dest2;
	const char *src = ft_strdup(" World");
	size_t	size = 6;

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcat(dest1, dest2, src, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcat(dest1, dest2, NULL, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcat(dest1, dest2, NULL, 1);// セグフォが起きるが正しい

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcat(dest1, dest2, NULL, 0);// セグフォが起きるが正しい

	my_test_strlcat(NULL, NULL, src, size);
	my_test_strlcat(NULL, NULL, src, 1);// セグフォが起きるが正しい
	my_test_strlcat(NULL, NULL, src, 0);// セグフォが起きないが正しい

	my_test_strlcat(NULL, NULL, NULL, size);
	my_test_strlcat(NULL, NULL, NULL, 1);// セグフォが起きるが正しい
	my_test_strlcat(NULL, NULL, NULL, 0);// セグフォが起きるが正しい
	free(src);
}


#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 

void	my_test_strlcpy(char *dest1, char *dest2,char *src, size_t size)
{
	
	pid_t pid;
	pid_t wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;

	size_t	expect;
	size_t	actual;

	printf("====test(%s,%s,%s,%zu)\n",dest1, dest2, src, size);
	pid = fork();
	if (pid == 0)
	{
		expect = strlcpy(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		actual = ft_strlcpy(dest2, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_actual);
	}

	assert(WIFEXITED(status_expect) == WIFEXITED(status_actual));
	assert(WIFSIGNALED(status_expect) == WIFSIGNALED(status_actual));
	if (WIFEXITED(status_expect))
	{
		expect = strlcpy(dest1, src, size);
		actual = ft_strlcpy(dest2, src, size);
		printf("  %zu：expect\n", expect);
		printf("  %zu：actual\n", actual);
		assert(expect == actual);
	}
	else if(WIFSIGNALED(status_expect))
	{
		printf(" Sig Abort \n");
		assert(WTERMSIG(status_actual) == WTERMSIG(status_expect));
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual) );
	}
	free(dest1);
	free(dest2);
}

int	testmain_strlcpy(void)
{

	char *dest1;
	char *dest2;
	char *src = ft_strdup(" World");
	size_t	size = 6;

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, size+100);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, size);


	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, 1);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, 0);

	dest1 = ft_strdup("");
	dest2 = ft_strdup("");
	my_test_strlcpy(dest1, dest2, src, size+100);

	dest1 = ft_strdup("");
	dest2 = ft_strdup("");
	my_test_strlcpy(dest1, dest2, src, size);


	dest1 = ft_strdup("");
	dest2 = ft_strdup("");
	my_test_strlcpy(dest1, dest2, src, 1);

	dest1 = ft_strdup("");
	dest2 = ft_strdup("");
	my_test_strlcpy(dest1, dest2, src, 0);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, size+100);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, 1);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, 0);

	my_test_strlcpy(NULL, NULL, src, size);
	my_test_strlcpy(NULL, NULL, src, 1);
	my_test_strlcpy(NULL, NULL, src, 0);

	my_test_strlcpy(NULL, NULL, NULL, size);
	my_test_strlcpy(NULL, NULL, NULL, 1);
	my_test_strlcpy(NULL, NULL, NULL, 0);
	free(src);
}


#include <string.h>
#include <xlocale.h>
#include <stdio.h>
#include <assert.h> 

void	my_test_strnstr(const char *haystack, const char *needle, size_t len)
{
	
	pid_t	pid;
	pid_t	wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;
	char	*expect;
	char	*actual;

	printf("====test(%s,%s,%zu)\n",haystack, needle, len);
	pid = fork();
	if (pid == 0)
	{
		expect = strnstr(haystack, needle, len);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		actual = ft_strnstr(haystack, needle, len);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_actual);
	}

	assert(WIFEXITED(status_expect) == WIFEXITED(status_actual));
	assert(WIFSIGNALED(status_expect) == WIFSIGNALED(status_actual));
	if (WIFEXITED(status_expect))
	{
		expect = strnstr(haystack, needle, len);
		actual = ft_strnstr(haystack, needle, len);
		printf("  %s：expect\n", expect);
		printf("  %s：actual\n", actual);
		if (expect == NULL &&  actual == NULL)
			return ;
		if (expect == NULL || actual == NULL)
			assert(0);
		assert(!strncmp(expect, actual,len));
	}
	else
	{
		printf(" Sig Abort \n");
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual));
	}
}


int	testmain_strnstr(void)
{
	const char *s1 = ft_strdup("2");
	const char *s2 = ft_strdup("2");

	my_test_strnstr(s1,s2,3);
	my_test_strnstr(s1,s2,2);
	my_test_strnstr(s1,s2,1);
	my_test_strnstr(s1,s2,0);
	my_test_strnstr(s1,NULL,0);
	my_test_strnstr(NULL,s2,0);
	my_test_strnstr(NULL,NULL,0);
	my_test_strnstr(s1,NULL,1);
	my_test_strnstr(NULL,s2,1);
	my_test_strnstr(NULL,NULL,1);
	my_test_strnstr(s1,NULL,2);
	my_test_strnstr(NULL,s2,2);
	my_test_strnstr(NULL,NULL,2);
	my_test_strnstr(s1,NULL,3);
	my_test_strnstr(NULL,s2,3);
	my_test_strnstr(NULL,NULL,3);
	my_test_strnstr("abbbcdefg", "bbc", 1);
	my_test_strnstr("abbbcdefg", "bbc", 5);
	my_test_strnstr("abbbcdefg", "bbc", 100);
	my_test_strnstr("ab", "abcdefgh", 1);
	my_test_strnstr("ab", "abcdefgh", 5);
	my_test_strnstr("ab", "abcdefgh", 100);
	free(s1);
	free(s2);
}


int	main(void)
{
	testmain_atoi();
	testmain_itoa();
	testmain_memmove();
	testmain_split();
	testmain_strlcat();
	testmain_strlcpy();
	testmain_strnstr();

	system("leaks a.out");
	return (0);
}