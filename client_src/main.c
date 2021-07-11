#include "../include/minitalk.h"

void	puterr_exit(void)
{
	ft_putendl_fd("error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	send_char(pid_t pid, char c)
{
	int bit;
	int	i;
	int	err;

	i = 0;
	while (i < 8)
	{
		usleep(100);
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
	int	i;
	char *str = argv[2];

	i = 0;
	while (str[i])
	{
		send_char(server_pid, str[i]);
		i++;
	}
	send_char(server_pid, EOT);
}

static void	print_client_pid(void)
{
	ft_putstr_fd("CLIENT PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}

void	handler(pid_t signo)
{
	ft_putendl_fd("Successfully sent message.", STDOUT_FILENO);
}

void	receive_ack(void)
{
	struct sigaction act;

	act.sa_handler = &handler;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_putendl_fd("invalid arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	receive_ack();
	print_client_pid();
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv);
	while (1)
	{
		if (sleep(5))
			break ;
		else
			puterr_exit();
	}
	return (0);
}
