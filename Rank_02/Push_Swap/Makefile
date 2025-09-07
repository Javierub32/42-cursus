CC        = cc
CFLAGS    = -Wall -Wextra -Werror \
            -I./lib/libft -I./lib/printf -I./includes

NAME      = push_swap

BLUE	  = \033[94m
RESET	  = \033[0m

LIBFT_DIR  = lib/libft
PRINTF_DIR = lib/printf
LIBFT      = $(LIBFT_DIR)/libft.a
PRINTF  = $(PRINTF_DIR)/libftprintf.a

SRCDIR    = src
SRC       = $(SRCDIR)/push_swap.c \
            $(SRCDIR)/utils/parse_arguments.c \
            $(SRCDIR)/utils/extra_utilities.c \
			$(SRCDIR)/utils/stack_init.c \
			$(SRCDIR)/utils/stack_utilities.c \
			$(SRCDIR)/operations/push.c \
			$(SRCDIR)/operations/swap.c \
			$(SRCDIR)/operations/rotate.c \
			$(SRCDIR)/operations/reverse_rotate.c \
			$(SRCDIR)/algorithm/radix_sort.c

OBJ       = $(SRC:.c=.o)

.PHONY: all clean fclean re bonus compile run

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@echo  "$(BLUE)>> Compilando libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "$(BLUE)>> Compilando ft_printf...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	@echo "$(BLUE)>> Compilando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)
	@echo "$(BLUE)>> Compilación exitosa $(NAME)$(RESET)"

%.o: %.c
	@echo " CC $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)>> Limpiando objetos...$(RESET)"
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	@echo "$(BLUE)>> Limpiando ejecutable y librerías...$(RESET)"
	@rm -f $(NAME)
	@rm -f $(LIBFT) $(PRINTF)

re: fclean all

run: $(NAME)
	@echo "$(BLUE)>> Ejecutando $(NAME)...\n$(RESET)"
	@./$(NAME)
