NAME	=	server

SRC		=	main.c
OBJ		=	$(SRC:.c=.o)

INCLUDE	=	../include

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

LIBFT_DIR	=	../libft
LIBFT		=	$(LIBFT_DIR)/libft.a

all	:	$(NAME)

$(NAME) :	$(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ) $(LIBFT)  -o $@

.c.o :
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean :
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJ) $(NAME)

