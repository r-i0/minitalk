#include "libft.h"

int	error_check(long num, const char *str, int negative, int i)
{
	long	real_num;

	real_num = num * negative;
	if (!ft_isdigit(str[i]) || (negative == 1 && real_num > INT_MAX)
		|| (negative == -1 && real_num < INT_MIN))
		return (0);
	return (1);
}

int	*ft_atoi(const char *str)
{
	int		i;
	int		negative;
	long	num;
	int		*ret;

	i = -1;
	num = 0;
	negative = 1;
	if (str[++i] == '-')
	{
		negative = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		num *= 10;
		num += str[i] - '0';
		if (!error_check(num, str, negative, i))
			return (NULL);
		i++;
	}
	i = (int)num * negative;
	ret = &i;
	return (ret);
}
