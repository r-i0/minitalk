NAME	=	client

SRC		=	main.c send_message.c
B_SRC	=	main_bonus.c send_message_bonus.c
OBJ		=	$(SRC:.c=.o)
B_OBJ	=	${B_SRC:.c=.o}

INCLUDE	=	../include/

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

LIBFT_DIR	=	../libft/
LIBFT		=	$(LIBFT_DIR)libft.a

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ) $(LIBFT) -o $@

.c.o	:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ) $(B_OBJ)

fclean	:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJ) $(B_OBJ) $(NAME)

re	:	fclean all

bonus	:	$(NAME) $(B_OBJ)

.PHONY	:	all clean fclean re