#include "libft.h"

static char	*make_str(const char *s, char c, int from, int i)
{
	int		j;
	char	*new_str;

	j = 0;
	new_str = (char *)malloc(sizeof(char) * (i - from + 2));
	if (!new_str)
		return (0);
	while (from < i)
	{
		new_str[j] = s[from];
		from++;
		j++;
	}
	if (s[i + 1] == '\0' && s[i] != c)
	{
		new_str[j] = s[i];
		new_str[j + 1] = '\0';
	}
	else
	{
		new_str[j] = '\0';
	}
	return (new_str);
}

static void	ft_free_str(char **split, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	check_split(char const *s, char c, int i)
{
	if (s[0] && s[0] != c && s[1] == '\0')
	{
		return (1);
	}
	if (i > 0 && ((s[i] == c && s[i - 1] != c)
			|| (!s[i + 1] && s[i] != c && s[0])))
	{
		return (1);
	}
	return (0);
}

static char	**ft_split_str(char **split, char const *s, char c)
{
	int	i;
	int	j;
	int	from;

	i = -1;
	j = 0;
	from = 0;
	while (s[++i])
	{
		if (check_split(s, c, i))
		{
			if (from == 0 && s[0] != c)
				split[j] = make_str(s, c, from, i);
			else
				split[j] = make_str(s, c, from + 1, i);
			if (!split[j])
				ft_free_str(split, j);
			j++;
			from = i;
		}
		if (s[i] == c && s[i - 1] == c)
			from = i;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (check_split(s, c, i))
			cnt++;
		i++;
	}
	split = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!split)
		return (NULL);
	return (ft_split_str(split, s, c));
}
