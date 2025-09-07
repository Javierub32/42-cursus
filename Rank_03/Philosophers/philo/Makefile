CC        = cc
CFLAGS    = -Wall -Wextra -Werror \
            -I./includes

NAME      = philo

BLUE	  = \033[94m
RESET	  = \033[0m

SRCDIR    = src
SRC       = $(SRCDIR)/philosophers.c \
			$(SRCDIR)/errors/error_handling.c \
			$(SRCDIR)/errors/error_utils.c \
			$(SRCDIR)/utils/ft_atol.c \
			$(SRCDIR)/utils/time_utils.c \
			$(SRCDIR)/utils/init_data.c \
			$(SRCDIR)/utils/clean_data.c \
			$(SRCDIR)/simulation/start_simulation.c \
			$(SRCDIR)/simulation/routine.c \
			$(SRCDIR)/simulation/actions.c

OBJ       = $(SRC:.c=.o)

.PHONY: all clean fclean re bonus compile run

all:  $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)>> Compilando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(BLUE)>> Compilación exitosa $(NAME)$(RESET)"

%.o: %.c
	@echo " CC $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)>> Limpiando objetos...$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(BLUE)>> Limpiando ejecutable y objetos...$(RESET)"
	@rm -f $(NAME)

re: fclean all
