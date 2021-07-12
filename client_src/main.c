#include "../include/minitalk.h"

void	puterr_exit(void)
{
	ft_putendl_fd("error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	print_client_pid(void)
{
	ft_putstr_fd("CLIENT PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}

static void	handler(pid_t signo)
{
	ft_putendl_fd("Successfully sent message.", STDOUT_FILENO);
}

static void	receive_ack(void)
{
	struct sigaction	act;

	act.sa_handler = &handler;
	sigemptyset(&act.sa_mask);//
	sigaction(SIGUSR1, &act, NULL);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc == 3)
		server_pid = ft_atoi(argv[1]);
	if (argc != 3 || kill(server_pid, 0) == -1)
		puterr_exit();
	receive_ack();
	print_client_pid();
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
