NAME = libft.a
HEADER = $(NAME:.a=.h)
SRCS = $(filter-out $(BSRCS), $(wildcard *.c))
BSRCS = $(wildcard *lst*.c)
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)	
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
RM = rm -f
AR = ar rc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

bonus: $(OBJS) $(BOBJS)
	$(AR) $(NAME) $^

%.o: %.c $(HEADER) $(CC) $(CFLAGS) $<

clean:
	${RM} $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
