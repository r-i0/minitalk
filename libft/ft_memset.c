#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*ans;
	unsigned char	c;

	c = ch;
	ans = (unsigned char *)buf;
	while (n)
	{
		*(ans) = c;
		ans++;
		n--;
	}
	return (buf);
}
