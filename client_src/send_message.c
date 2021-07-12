#include "../include/minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	bit;
	int	i;
	int	err;

	i = 0;
	while (i < 8)
	{
		usleep(50);
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				puterr_exit();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				puterr_exit();
		}
		i++;
	}
}

void	send_message(pid_t server_pid, char **argv)
{
	int		i;
	char	*str;

	str = argv[2];
	i = 0;
	while (str[i])
	{
		send_char(server_pid, str[i]);
		i++;
	}
	send_char(server_pid, EOT);
}
