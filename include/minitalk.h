#ifndef MINITALK_H
# define MINITALK_H
# define EOT 0x4
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include "../libft/libft.h"

// send_message.c
void	send_message(pid_t server_pid, char **argv);
void	send_char(pid_t pid, char c);

// client main.c
void	puterr_exit(void);

// receive_bit.c
void	print_message(char *buf, int j, pid_t client_pid);
void	receive_bit(int bit, pid_t client_pid);

#endif