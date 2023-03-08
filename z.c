#include "libft.h"

#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

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
	unsigned long	acc;

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
	return (acc);
}


int main(void)
{
	printf("%ld\n", LONG_MAX);
	// printf("%d\n", atoi("9223372036854775808"));
	// printf("%d\n", ft_atoi("9223372036854775808"));
	printf("%d\n", ft_atoi("-10"));
}