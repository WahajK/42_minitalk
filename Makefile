SOURCES = server.c client.c
OBJS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : server client

libft:
	make -C libft

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) 

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f server client
	make -C libft fclean

re: fclean all