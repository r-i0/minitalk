NAME	=	client

SRC		=	main.c send_message.c
OBJ		=	$(SRC:.c=.o)

INCLUDE	=	../include/

CC		=	gcc
CFLAGFS	=	-Wall -Wextra -Werror
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
	$(RM) $(OBJ)

fclean	:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJ) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re