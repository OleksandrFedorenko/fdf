/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:06:28 by afedoren          #+#    #+#             */
/*   Updated: 2018/10/29 12:06:31 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# define WIN 1000

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct		s_coord
{
	double				x;
	double				y;
	double				z;
}					t_coord;

typedef struct		s_tool
{
	void			*mlx;
	void			*win;
	int				c_rows;
	int				c_colum;
	size_t			color;
	double			step;
	t_coord			**aray;
	int				temp;

	int				main_x;
	int				main_y;

	int				main_xx;
	int				main_yy;

	int				delta_x;
	int				delta_y;
	int				sign_x;
	int				sign_y;
	int				error;

	int				d_else;
	int				d1_else;
	int				d2_else;
	int				x_else;
	int				y_else;

	int				d_if;
	int				d1_if;
	int				d2_if;
	int				x_if;
	int				y_if;

	int				i_arr;
	int				j_arr;
	int				j_j;
	int				i_val;
	int				i_mall;
	int				i_colum;
	int				i_else;
	int				i_if;
	int				paint_i;
	int				paint_j;
	int				k;
}					t_tool;

void				ft_error(char *line);
void				make_list(t_line **head, char *line, t_tool *tool);
void				init_tool(t_tool *tool);
void				print_list(t_line *head);
void				count_colum(t_line *head, t_tool *tool);
void				malloc_arr(t_tool *tool);
void				attack_tmp_arr(t_tool *tool, t_line *head);
void				free_arr(char **arr, t_tool *tool);
void				attack_main_arr(char **tmp_arr, t_tool *tool);
void				creat_coord(char *tmp_arr, t_tool *tool);
void				painting_map(t_tool *tool);
void				uncle_brezenheim(t_tool *tool, t_coord c1, t_coord c2);
size_t				ft_abs(int n);
void				shift(t_tool *tool);
void				x_transform(t_tool *tool);
void				y_transform(t_tool *tool);
void				validation(t_tool *tool, t_line *head);
void				just_exit(void *param);
int					deal_key(int key, t_tool *tool);
void				move_left(t_tool *tool, int step);
void				help_painting_map(t_tool *tool, int	i_tmp, int	j_tmp);
void				help_main(t_line *head, t_tool *tool);
void				help_uncle(t_tool *tool, t_coord c1, t_coord c2);
void				proc_if(t_tool *tool, t_coord c1, t_coord c2);
void				proc_else(t_tool *tool, t_coord c1, t_coord c2);
void				help_else(t_tool *tool, t_coord c1, t_coord c2);
void				help_if(t_tool *tool, t_coord c1, t_coord c2);

#endif
