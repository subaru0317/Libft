#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	const char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (const char *)src;
	while (len--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = strlen(src);
	if (src_len + 1 <= dstsize)
		ft_memcpy(dst, src, src_len + 1);
	else
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (strlen(src));
}
int main(void)
{
	char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);
	char ft_dest[10]; memset(dest, 'A', 10);
    strlcpy(dest, src, 8);
    ft_strlcpy(ft_dest, src, 8);
    printf("ft_dest: %s\n", ft_dest);
    printf("dest   : %s\n", dest);
}