NAME        := libftprintf.a

EXEC        := main

CC          := cc
CFLAGS      := -Wall -Wextra -Werror

SRCS        := ft_printf.c printf_utils.c
OBJS        := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	@$(CC) $(CFLAGS) main.c $(NAME) -o $(EXEC)
	@./$(EXEC)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: all run clean fclean re
