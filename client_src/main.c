#include "../include/minitalk.h"

void	send_char(pid_t pid, char c)
{
	int bit;
	int	i;
	int	err;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

size_t	record_strlen(char *str)
{
	static size_t	len;

	if (str)
	{
		len = ft_strlen(str);
	}
	return (len);
}

void	send_message(pid_t server_pid, char **argv)
{
	int	i;
	char *str = argv[2];

	i = 0;
	record_strlen(str);
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
	static int	cnt;

	if (signo == SIGUSR1)
	{
		cnt++;
		if (cnt == record_strlen(NULL))
		{
			ft_putendl_fd("Successfully sent message.", STDOUT_FILENO);
		}
	}
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
		write(STDOUT_FILENO, "invalid argument\n", 17);
		exit(EXIT_FAILURE);
	}
	receive_ack();
	print_client_pid();
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv);
	return (0);
}
