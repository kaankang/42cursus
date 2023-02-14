/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:24:28 by kkanig            #+#    #+#             */
/*   Updated: 2023/01/31 21:01:59 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PL_FT "./textures/background.xpm"
# define PL_TT "./textures/wall.xpm"
# define PL_DT "./textures/sungerbob.xpm"
# define PL_ST "./textures/exit.xpm"
# define PL_XT "./textures/coin.xpm"

# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void	*window;
	void	*mlx;
	char	*map;
	int		fd;
	char	**split;
	char	**test;
	int		coin;
	int		player;
	int		exit;
	int		map_x;
	int		map_y;
	int		line;
	int		column;
	int		exitx;
	int		exity;
	int		step;
	void	**image;
	int		position_x;
	int		position_y;
	int		image_x;
	int		image_y;
}			t_list;

char		*get_next_line(int fd);
char		*ft_read(int fd, char *buffer);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strchr(char *s);
int			ft_strlen(char *str);
void		create_map(t_list *data, char *file);
char		map_wall_control(t_list *data);
void		cpe_control(t_list *data);
void		side_wall_control(t_list *data);
void		map_split(t_list *data);
char		**ft_split(char const *s, char c);
void		map_coin_control(t_list *data);
void		map_control(t_list *data);
void		map_exit(t_list *data);
void		ft_window(t_list *data);
void		back_ground(t_list *data);
int			keyboard(int key, t_list *data);
void		down_move(t_list *data);
void		up_move(t_list *data);
void		right_move(t_list *data);
void		left_move(t_list *data);
void		map_character_control(t_list *data);
void		map_exit_control(t_list *data);
void		back_ground2(t_list *data, int i, int j);
int			window_close(void);
void		ber_check(char *str);
void		put_step(t_list *data);
char		*ft_itoa(int n);
void		step_plus(t_list *data);
void		space_line(t_list *data);

#endif
