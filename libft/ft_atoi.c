#include "libft.h"

static int	cnt_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

static int	check_over(long num, const char *str, int i, int negative)
{
	long	ov_div;
	long	p_ov_mod;
	long	m_ov_mod;
	long	n;

	n = str[i] - '0';
	ov_div = LONG_MAX / 10;
	p_ov_mod = LONG_MAX % 10;
	m_ov_mod = (LONG_MIN % 10) * -1;
	if (num > ov_div && negative == 1)
		return (1);
	if (num > ov_div && negative == -1)
		return (-1);
	if (num == ov_div && n > p_ov_mod && negative == 1)
		return (1);
	if (num == ov_div && n > m_ov_mod && negative == -1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		negative;
	long	num;

	i = cnt_space(str);
	num = 0;
	negative = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (check_over(num, str, i, negative) == 1)
			return (-1);
		if (check_over(num, str, i, negative) == -1)
			return (0);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return ((int)num * negative);
}
