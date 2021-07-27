#include "../include/minitalk.h"

static void	print_message(char *buf, int j, pid_t client_pid)
{
	ft_putstr_fd(buf, STDOUT_FILENO);
	if (buf[j] == EOT)
	{
		ft_putendl_fd("", STDOUT_FILENO);
		usleep(100);
		kill(client_pid, SIGUSR1);
	}
}

void	receive_bit(int bit, pid_t client_pid)
{
	static char	c;
	static char	buf[1024];
	static int	i;
	static int	j;

	if (i < 8)
	{
		c += (bit << i);
		i++;
	}
	if (i == 8)
	{
		buf[j] = c;
		if (buf[j] == EOT || j >= 1000)
		{
			print_message(buf, j, client_pid);
			j = -1;
			ft_bzero(buf, 1024);
		}
		j++;
		c = 0;
		i = 0;
	}
}
