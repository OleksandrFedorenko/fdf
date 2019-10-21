/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:18:26 by afedoren          #+#    #+#             */
/*   Updated: 2018/10/28 19:18:30 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int ac, char **av)
{
	char	*line;
	int		fd;
	t_tool	*tool;
	t_line	*head;

	tool = (t_tool*)ft_memalloc(sizeof(t_tool));
	init_tool(tool);
	line = NULL;
	head = NULL;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_DIRECTORY)) > 0)
			ft_error("no file");
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
			make_list(&head, line, tool);
	}
	else
		ft_error("usage: ./fdf <map-file>");
	if (line == NULL)
		ft_error("No data found.");
	help_main(head, tool);
	return (0);
}

void		help_main(t_line *head, t_tool *tool)
{
	count_colum(head, tool);
	validation(tool, head);
	malloc_arr(tool);
	attack_tmp_arr(tool, head);
	tool->mlx = mlx_init();
	tool->win = mlx_new_window(tool->mlx, 3000, 3000, "FDF");
	x_transform(tool);
	y_transform(tool);
	painting_map(tool);
	mlx_hook(tool->win, 2, 5, deal_key, tool);
	mlx_loop(tool->mlx);
}

void		attack_tmp_arr(t_tool *tool, t_line *head)
{
	t_line	*ptr;
	char	**tmp_arr;

	ptr = head;
	tool->j_j = 0;
	while (ptr)
	{
		tmp_arr = ft_strsplit(ptr->line, ' ');
		attack_main_arr(tmp_arr, tool);
		free_arr(tmp_arr, tool);
		ptr = ptr->next;
		tool->j_j++;
	}
}

void		attack_main_arr(char **tmp_arr, t_tool *tool)
{
	tool->j_arr = tool->j_j;
	tool->i_arr = 0;
	while (tmp_arr[tool->i_arr])
	{
		creat_coord(tmp_arr[tool->i_arr], tool);
		tool->i_arr++;
	}
}

void		creat_coord(char *tmp_arr, t_tool *tool)
{
	t_coord	coord;

	coord.x = 0;
	coord.y = 0;
	coord.z = 0;
	coord.x = tool->i_arr;
	coord.y = tool->j_arr;
	coord.z = ft_atoi(tmp_arr);
	tool->aray[tool->j_arr][tool->i_arr] = coord;
}
