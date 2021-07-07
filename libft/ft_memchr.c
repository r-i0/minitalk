#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	unsigned char	*s1;
	unsigned char	s2;

	s1 = (unsigned char *)buf;
	s2 = (unsigned char )ch;
	while (n)
	{
		if (*s1 == s2)
			return (s1);
		s1++;
		n--;
	}
	return (0);
}
