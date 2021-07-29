NAME		=	$(SERVER) $(CLIENT)
SERVER		=	server
CLIENT		=	client

INCLUDE	=	./include/

SERVER_DIR	=	./server_src
CLIENT_DIR	=	./client_src
LIBFT_DIR	=	./libft

LIBFT	=	$(LIBFT_DIR)/libft.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $(<:.c=.o)

all	:	$(NAME)

$(SERVER)	:	$(SERVER_DIR)
	@$(MAKE) -C $(SERVER_DIR)
	cp $(SERVER_DIR)/$(SERVER) ./

$(CLIENT)	:	$(CLIENT_DIR)
	@$(MAKE) -C $(CLIENT_DIR)
	cp $(CLIENT_DIR)/$(CLIENT) ./

clean 	:
	$(MAKE) -C $(SERVER_DIR) clean
	$(MAKE) -C $(CLIENT_DIR) clean

fclean	:
	$(MAKE) -C $(SERVER_DIR) fclean
	$(MAKE) -C $(CLIENT_DIR) fclean
	$(RM) $(SERVER) $(CLIENT)

re	:	fclean all

bonus	:
	@$(MAKE) -C $(SERVER_DIR) bonus
	@$(MAKE) -C $(CLIENT_DIR) bonus
	cp $(SERVER_DIR)/$(SERVER) ./
	cp $(CLIENT_DIR)/$(CLIENT) ./

.PHONY	:	all clean fclean re



