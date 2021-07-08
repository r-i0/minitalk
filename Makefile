NAME	=	minitalk
SERVER	=	server
CLIENT	=	client

INCLUDE	=	./include/

SERVER_DIR	=	./server_src
CLIENT_DIR	=	./client_src
LIBFT_DIR	=	./libft

LIBFT	=	$(LIBFT_DIR)/libft.a

SERVER_SRC	=	$(SERVER_DIR)/main.c
SERVER_OBJ	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	$(CLIENT_DIR)/main.c
CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -rf

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $(<:.c=.o)

$(LIBFT)	:
	make -C $(LIBFT_DIR)

$(NAME)		:	$(OBJ) $(SERVER) $(CLIENT)

$(SERVER)	:	$(OBJ)


