#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	len;

	if (!(count * size))
		len = 1;
	else
		len = count * size;
	p = (void *)malloc(len);
	if (!p)
		return (0);
	ft_bzero(p, len);
	return (p);
}
