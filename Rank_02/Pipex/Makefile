CC        = cc
CFLAGS    = -Wall -Wextra -Werror \
            -I./lib/libft -I./lib/printf -I./includes

NAME      = pipex

BLUE	  = \033[94m
RESET	  = \033[0m

LIBFT_DIR  = lib/libft
PRINTF_DIR = lib/printf
LIBFT      = $(LIBFT_DIR)/libft.a
PRINTF  = $(PRINTF_DIR)/libftprintf.a

SRCDIR    = src
SRC       = $(SRCDIR)/pipex.c \
			$(SRCDIR)/error_utils.c \
			$(SRCDIR)/pipex_utils.c \
			$(SRCDIR)/command_utils.c \
			$(SRCDIR)/child_process_handler.c 

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
