CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = libft.h
NAME = libft.a

SRC = src/ft_isalpha.c src/ft_isdigit.c src/ft_isalnum.c src/ft_isascii.c src/ft_isprint.c \
    src/ft_strlen.c src/ft_memset.c src/ft_bzero.c src/ft_memcpy.c src/ft_memmove.c src/ft_strlcpy.c \
    src/ft_strlcat.c src/ft_toupper.c src/ft_tolower.c src/ft_strchr.c src/ft_strrchr.c src/ft_strncmp.c \
    src/ft_memchr.c src/ft_memcmp.c src/ft_strnstr.c src/ft_atoi.c src/ft_calloc.c src/ft_strdup.c src/ft_substr.c \
    src/ft_strjoin.c src/ft_strtrim.c src/ft_split.c src/ft_itoa.c src/ft_strmapi.c src/ft_striteri.c src/ft_putchar_fd.c \
    src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/bonus.c src/check_format.c src/ft_printf.c src/ft_puthexa_p.c \
    src/ft_puthexa.c src/ft_putnbr.c src/ft_puts.c src/size.c src/get_next_line.c src/get_next_line_utils.c

OBJS_BASE = $(SRC:.c=.o)
OBJ_PATH = lib_obj/
OBJS = $(addprefix $(OBJ_PATH),$(OBJS_BASE))

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_PATH):
	mkdir -p lib_obj/src/

clean:
	rm -rf $(OBJ_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
