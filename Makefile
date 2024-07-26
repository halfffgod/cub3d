NAME 	= cub3D

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror #-fsanitize=address -g

SRCS = $(wildcard *.c) $(wildcard */*.c)

HEADER = cub.h

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
	$(CC) ${CFLAGS} -lmlx -framework OpenGL -framework AppKit  $^ -o $@
%.o:%.c ${HEADER} Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all