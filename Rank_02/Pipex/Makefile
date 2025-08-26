CC        = cc
CFLAGS    = -Wall -Wextra -Werror -g\
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

SRC_BONUS = $(SRCDIR)/pipex_bonus.c \
			$(SRCDIR)/error_utils_bonus.c \
			$(SRCDIR)/pipex_utils_bonus.c \
			$(SRCDIR)/command_utils_bonus.c \
			$(SRCDIR)/child_process_handler_bonus.c

OBJ       = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HEADER    = includes/pipex.h

.PHONY: all clean fclean re bonus compile run

all: $(LIBFT) $(PRINTF) $(NAME)

bonus: $(LIBFT) $(PRINTF) $(NAME)_bonus

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

$(NAME)_bonus: $(OBJ_BONUS)
	@echo "$(BLUE)>> Compilando $(NAME) bonus...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME)_bonus $(OBJ_BONUS) $(LIBFT) $(PRINTF)
	@echo "$(BLUE)>> Compilación exitosa $(NAME) bonus$(RESET)"


%.o: %.c $(HEADER)
	@echo " CC $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)>> Limpiando objetos...$(RESET)"
	@rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	@echo "$(BLUE)>> Limpiando ejecutable y librerías...$(RESET)"
	@rm -f $(NAME) $(NAME)_bonus
	@rm -f $(LIBFT) $(PRINTF)

re: fclean all

run: $(NAME)
	@echo "$(BLUE)>> Ejecutando $(NAME)...\n$(RESET)"
	@./$(NAME)
