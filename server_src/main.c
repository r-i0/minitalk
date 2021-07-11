#include "../include/minitalk.h"

void	print_message(char *buf, int j, pid_t client_pid)
{
	ft_putstr_fd(buf, STDOUT_FILENO);
	if (buf[j] == EOT)
	{
		ft_putendl_fd("", STDOUT_FILENO);
		sleep(1);
		kill(client_pid, SIGUSR1);
	}
	(void)client_pid;
}

void	sig_restore(int bit, pid_t client_pid)
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

static void	action(int signo, siginfo_t *info, void *c)
{
	static pid_t pid;

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
		sig_restore(1, info->si_pid);
	}
	else if (signo == SIGUSR2)
	{
		sig_restore(0, info->si_pid);
	}
}

static void	set_signal(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &action;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

static void	print_pid(void)
{
	ft_putstr_fd("SERVER PID : ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("invalid arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	set_signal();
	print_pid();
	while (1)
	{
		;
	}
	return (0);
}