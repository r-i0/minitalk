#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <limits.h>
#include "../libft/libft.h"

void printb(unsigned int v)
{
	unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
	do putchar(mask & v ? '1' : '0');
	while (mask >>= 1);
	printf("\n");
}

void	send_char(pid_t pid, char c)
{
	int bit;
	int	i;
	int	err;

	i = 0;
	printf("%d\n", c);
	printb(c);
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		printf("err: %d\n", err);
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
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		return (1);
	}
	printf("crient pid: %d\n", getpid());
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv);
	return (0);
}
