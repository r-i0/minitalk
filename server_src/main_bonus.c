#include "../include/minitalk_bonus.h"

void	puterr_exit(void)
{
	ft_putendl_fd("error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	action(int signo, siginfo_t *info, void *c)
{
	static pid_t	pid;

	(void)c;
	if (pid != info->si_pid)
	{
		ft_putstr_fd("from ", STDOUT_FILENO);
		ft_putnbr_fd(info->si_pid, STDOUT_FILENO);
		ft_putstr_fd(" : ", STDOUT_FILENO);
		pid = info->si_pid;
	}
	if (signo == SIGUSR1)
	{
		receive_bit(1, info->si_pid);
	}
	else if (signo == SIGUSR2)
	{
		receive_bit(0, info->si_pid);
	}
}

static void	set_signal(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &action;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		puterr_exit();
}

static void	print_pid(void)
{
	ft_putstr_fd("SERVER PID : ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}

int	main(void)
{
	set_signal();
	print_pid();
	while (1)
		;
}
