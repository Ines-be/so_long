/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:50:26 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:58:02 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ARROW_UP 65362
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_DOWN 65364
# define KEY_ARROW_RIGHT 65363

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include "../mlx/mlx.h"

typedef struct s_chars
{
	int		exit;
	int		player;
	int		collectible;
	int		monster;
	int		moves;
}			t_chars;
typedef struct s_game
{
	char	**map_og;
	char	**mapcopy;
	int		rows;
	int		cols;
	int		p_pos_x;
	int		p_pos_y;
	int		exit_pos_x;
	int		exit_pos_y;
	int		m_pos_x;
	int		m_pos_y;
	t_chars	*count;
}			t_game;

typedef struct s_mlx
{
	int		width;
	int		height;
	int		img_width;
	int		img_height;
	void	*mlx;
	void	*win;
	void	*img_grass;
	void	*img_p_front;
	void	*img_p_back;
	void	*img_p_left;
	void	*img_p_right;
	void	*img_item;
	void	*img_exit;
	void	*img_wall;
	void	*img_m_front;
	void	*img_m_back;
	void	*img_m_left;
	void	*img_m_right;
	void	*img_you;
	void	*img_won;
	void	*img_game;
	void	*img_over;
	t_game	*map;
}			t_mlx;

// Parsing
void		name_check(char *str);
int			skip_path(char *str);
char		**fill_map(t_game *map, char *av);
int			count_rows(int fd);
void		check_map(t_game *map);
void		check_len(t_game *map);
void		check_first_and_last(t_game *map);
void		check_middles(t_game *map);
void		check_chars(t_game *map);
void		check_count(t_game *map, t_chars *count);
void		wall_fill(t_game *map, int row, int col);
void		check_path(t_game *map);
int			valid_char(char c, t_chars *count);
int			map_error(char *error, t_game *map);
void		open_error(void);
void		free_tab(char **tab);
void		free_line(int fd, char *line);
void		free_and_close(int fd, char *line);
int			tab_len(char **tab);
char		*dup_line(char *line);
void		init_map(t_game *map, char *av);
void		init_count(t_chars *count);
void		init_p_pos(t_game *map);
void		clean_exit(t_game *map);

// Game
void		init_mlx(t_mlx *game, t_game *map);
void		init_imgs(t_mlx *game);
void		init_p_imgs(t_mlx *game);
void		init_exit_pos(t_game *map);
int			update_pos(int keycode, t_mlx *game);
int			close_win(t_mlx *param);
int			background(t_mlx *game);
int			walls(t_mlx *game);
int			collectibles(t_mlx *game);
int			display_start(t_mlx *game);
int			display_exit(t_mlx *game);
int			p_front(t_mlx *game);
int			p_back(t_mlx *game);
int			p_left(t_mlx *game);
int			p_right(t_mlx *game);
void		move_player_right(t_mlx *game, int x, int y);
void		move_player_left(t_mlx *game, int x, int y);
void		move_player_down(t_mlx *game, int x, int y);
void		move_player_up(t_mlx *game, int x, int y);
void		display_moves(t_mlx *game);

// Bonus
void		init_m_imgs(t_mlx *game);
void		init_monster_pos(t_game *map);
void		init_bonus(t_mlx *game);
void		init_msg(t_mlx *game);
void		init_base(t_mlx *game);
void		destroy_monster(t_mlx *game);
void		move_monster_right(t_mlx *game, int m_x, int m_y);
void		move_monster_left(t_mlx *game, int m_x, int m_y);
void		move_monster_down(t_mlx *game, int m_x, int m_y);
void		move_monster_up(t_mlx *game, int m_x, int m_y);
void		arrow_right(t_mlx *game, int p_x, int p_y);
void		arrow_up(t_mlx *game, int p_x, int p_y);
void		arrow_left(t_mlx *game, int p_x, int p_y);
void		arrow_down(t_mlx *game, int p_x, int p_y);
int			m_front(t_mlx *game);
int			m_back(t_mlx *game);
int			m_left(t_mlx *game);
int			m_right(t_mlx *game);
void		check_p_pos(t_mlx *game);
void		check_m_pos(t_mlx *game);
void		you(t_mlx *game);
void		won(t_mlx *game);
void		you_won_msg(t_mlx *game);
int			you_won(t_mlx *game);
void		game_msg(t_mlx *game);
void		over(t_mlx *game);
void		game_over_msg(t_mlx *game);
int			game_over(t_mlx *game);
void		end_game(t_mlx *game);

#endif