NAME = libftprintf.a

CC = cc

CCFLAG = -Wall -Wextra -Werror

AR = ar

ARFLAG = crs

SRCS_1 = ft_printf.c \
ft_leng.c \
ft_putchar.c \
ft_putnbr.c \
ft_putstr.c \
ft_strchr.c \
ft_puthexa.c \
ft_putptr.c \
ft_putnbr_u.c \

SRCS = $(SRCS_1)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
		$(AR) $(ARFLAG) $@ $^

%.o: %.c
		$(CC) $(CCFLAG) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re