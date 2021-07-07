#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cp;
	int		i;

	cp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!cp)
		return (0);
	i = 0;
	while (s1[i])
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
