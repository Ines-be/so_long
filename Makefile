CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = so_long.h
LIB = -L libft/ -lft mlx/libmlx_Linux.a
MLX = -lXext -lX11
NAME = so_long

SRC = src/check_map.c src/check_map2.c src/check_utils.c \
	src/display.c src/display_monster.c src/display_player.c \
	src/monster_utils.c src/exit.c src/free.c src/init.c \
	src/init_img.c src/main.c src/update_pos.c src/move_monster.c \
	src/move_player.c src/arrows.c src/you_won.c src/game_over.c

OBJS_BASE = $(SRC:.c=.o)
OBJ_PATH = obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJS_BASE))

all: $(OBJ_PATH) $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	make -C mlx/
	$(CC) $(CFLAGS) -I $(INCLUDE) $(MLX) -o $(NAME) $(OBJS) $(LIB)

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@ 

$(OBJ_PATH):
	mkdir -p obj/
	mkdir -p obj/src/

clean:
	make fclean -C libft/
	rm -rf $(OBJ_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re