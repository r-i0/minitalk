#include "../include/minitalk_bonus.h"

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

static int	get_server_pid(int argc, char **argv)
{
	int	*ret;

	ret = NULL;
	if (argc != 3)
		return (0);
	ret = ft_atoi(argv[1]);
	if (ret)
		return (*ret);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	server_pid = get_server_pid(argc, argv);
	if (kill(server_pid, 0) == -1)
		puterr_exit();
	receive_ack();
	print_client_pid();
	send_message(server_pid, argv);
	if (!sleep(5))
		puterr_exit();
	return (0);
}
