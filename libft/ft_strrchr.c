#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = 0;
	while (*s)
	{
		if (*s == c)
		{
			p = (char *)s;
		}
		s++;
	}
	if (*s == c)
		p = (char *)s;
	return (p);
}
