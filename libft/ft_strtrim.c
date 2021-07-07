#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		end_i;
	size_t		len;

	i = 0;
	if (!s1 || !set)
		return (0);
	end_i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[end_i]))
		end_i--;
	len = end_i - i + 1;
	return (ft_substr(s1, i, len));
}
