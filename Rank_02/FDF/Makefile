CC        = cc
CFLAGS    = -Wall -Wextra -Werror \
            -I./lib/libft -I./lib/printf -I./includes -I./lib/minilibx-linux -I./lib/get_next_line

NAME      = fdf

BLUE	  = \033[94m
RESET	  = \033[0m

LIBFT_DIR  = lib/libft
PRINTF_DIR = lib/printf
GNL_DIR    = lib/get_next_line
MLX_DIR    = lib/minilibx-linux
LIBFT      = $(LIBFT_DIR)/libft.a
PRINTF     = $(PRINTF_DIR)/libftprintf.a
GNL_SRC    = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJ    = $(GNL_SRC:.c=.o)
MLX        = $(MLX_DIR)/libmlx.a

SRCDIR    = srcs
SRC       = $(SRCDIR)/fdf.c \
			$(SRCDIR)/parsing/map_parsing.c \
			$(SRCDIR)/parsing/parsing_utils.c \
			$(SRCDIR)/error/error_handler.c \
			$(SRCDIR)/utils/clear_utils.c \
			$(SRCDIR)/points/points.c \
			$(SRCDIR)/events/events.c \
			$(SRCDIR)/drawing/draw.c \
			$(SRCDIR)/drawing/draw_utils.c \
			$(SRCDIR)/utils/init_window.c \
			$(SRCDIR)/utils/utils.c


HEADERS   = includes/fdf.h lib/get_next_line/get_next_line.h

OBJ       = $(SRC:.c=.o) $(GNL_OBJ)

.PHONY: all clean fclean re compile run

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(LIBFT):
	@echo  "$(BLUE)>> Compilando libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "$(BLUE)>> Compilando ft_printf...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR)

$(MLX):
	@echo "$(BLUE)>> Compilando MiniLibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	@echo "$(BLUE)>> Compilando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) -lXext -lX11 -lm
	@echo "$(BLUE)>> Compilación exitosa $(NAME)$(RESET)"

%.o: %.c $(HEADERS)
	@echo " CC $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)>> Limpiando objetos...$(RESET)"
	@rm -f $(OBJ)
	@rm -f $(GNL_OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	@echo "$(BLUE)>> Limpiando ejecutable y librerías...$(RESET)"
	@rm -f $(NAME)
	@rm -f $(LIBFT) $(PRINTF) $(MLX)

re: fclean all

run: $(NAME)
	@echo "$(BLUE)>> Ejecutando $(NAME)...\n$(RESET)"
	@./$(NAME)
