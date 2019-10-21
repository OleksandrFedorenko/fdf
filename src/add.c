/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:42:35 by afedoren          #+#    #+#             */
/*   Updated: 2018/10/28 18:42:53 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		count_colum(t_line *head, t_tool *tool)
{
	t_line	*ptr;
	char	**arr;

	ptr = head;
	arr = ft_strsplit(ptr->line, ' ');
	tool->i_colum = 0;
	while (arr[tool->i_colum])
	{
		tool->c_colum++;
		tool->i_colum++;
	}
	free_arr(arr, tool);
}

void		free_arr(char **arr, t_tool *tool)
{
	tool->i_mall = 0;
	while (arr[tool->i_mall])
	{
		free(arr[tool->i_mall]);
		tool->i_mall++;
	}
	free(arr);
}

void		malloc_arr(t_tool *tool)
{
	tool->i_mall = 0;
	tool->aray = (t_coord**)ft_memalloc(sizeof(t_coord*) * tool->c_rows);
	while (tool->i_mall < tool->c_rows)
	{
		tool->aray[tool->i_mall] = (t_coord*)ft_memalloc(sizeof(t_coord) *
		tool->c_colum);
		tool->i_mall++;
	}
	tool->i_mall = 0;
}

void		validation(t_tool *tool, t_line *head)
{
	t_line	*ptr;
	char	**arr;

	tool->i_val = 0;
	ptr = head;
	while (ptr)
	{
		arr = ft_strsplit(ptr->line, ' ');
		while (arr[tool->i_val])
			tool->i_val++;
		if (tool->i_val != tool->c_colum)
			ft_error(" WRONG LINE LENGTH");
		free_arr(arr, tool);
		ptr = ptr->next;
		tool->i_val = 0;
	}
}
