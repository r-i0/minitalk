#include "../include/minitalk.h"

static void	handler(pid_t signo)
{
	if (signo == SIGUSR1)
		ft_putendl_fd("Successfully sent message.", STDOUT_FILENO);
}

void	receive_ack(void)
{
	struct sigaction	act;

	act.sa_handler = &handler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		puterr_exit();
}
