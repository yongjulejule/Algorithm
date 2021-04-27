CC = gcc
dflags = -g3 -fsanitize=address
SRCDIR = srcs
INCDIR = includes
NAME = rbt
DEBUG = debug
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = ${SRCS:%.c=%.o}

.c.o:
	$(CC) -c $< -o $@ -I $(INCDIR)

all: $(NAME) clean

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

debug : $(DEBUG)

$(DEBUG) : $(SRCS)
	$(CC) $(dflags) $(SRCS) -o $(DEBUG) -I $(INCDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(wildcard $(DEBUG)*)
re: fclean all clean
