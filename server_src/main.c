#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	sig_restore(int signal)
{
	static int num;
	static char c;
	static int i;

	if (i < 8)
	{
		c += (signal << i);
		// printf("c: %d\n", c);
		i++;
	}
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

static void	action(int signo, siginfo_t *info, void *c)
{
	// printf("si_signo: %d\n", info->si_signo);
	// printf("si_code: %d\n", info->si_code);
	// printf("si_value: %d\n", info->si_value.sival_int);
	// printf("si_pid: %d\n", info->si_pid);
	if (signo == SIGUSR1)
	{
		sig_restore(1);
	}
	if (signo == SIGUSR2)
	{
		sig_restore(0);
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

void	print_pid(void)
{
	ft_putstr_fd("SERVER PID: ", 1);
	ft_putnbr_fd(getpid(),1);
	printf("\n");
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		exit(1);
	}
	set_signal();
	print_pid();
	while (1)
		pause();
	return (0);
}