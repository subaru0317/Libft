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
	int			neg;
	int			cutlim;
	unsigned long	cutoff;
	unsigned long	acc;
	int			any;

	s = nptr;
	c = *s++;
	while (ft_isspace((unsigned char)c))
		c = *s++;
	if (c == '-')
	{
		neg = 1;
		c = *s++;
	}
	else
	{
		neg = 0;
		if (c == '+')
			c = *s++;
	}
	if (neg)
		cutoff = LONG_MIN;
	else
		cutoff = LONG_MAX;
	cutlim = cutoff % 10;
	cutoff /= 10;
	acc = 0;
	any = 0;
	while (1)
	{
		if ('0' <= c && c <= '9')
			c -= '0';
		else
			break ;
		if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim)) // overflow
		{
			any = -1;
			if (neg)
				return ((int)LONG_MIN);
			else
				return ((int)LONG_MAX);
		}
		acc *= 10;
		acc += c;
		c = *s++;
		any = 1;
	}
	if (neg)
		acc *= -1;
	return (acc);
}


int main(void)
{
	printf("%d\n", atoi("18446744073709551614"));
	printf("%d\n", ft_atoi("18446744073709551614"));
}