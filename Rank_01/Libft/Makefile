# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files and objects
SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS_SRCS = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Default target


# Build the library from object files
$(NAME): $(SRCS) $(OBJS)
	@$(CC) -c $(CFLAGS) $(SRCS)
	@ar rcs $(NAME) $(OBJS)


all: $(NAME)

bonus: $(NAME) $(BONUS_SRCS) $(BONUS_OBJS)
	@$(CC) -c $(CFLAGS) $(BONUS_SRCS)
	@ar rcs $(NAME) $(BONUS_OBJS)

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files and library
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

run: $(NAME)
	@cc -Wall -Wextra -Werror main.c -L. -lft -o test_main
	@./test_main

# Declare phony targets
.PHONY: all clean fclean re

TEST_MAIN = test_main


