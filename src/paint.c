/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:01:47 by afedoren          #+#    #+#             */
/*   Updated: 2018/10/29 12:01:50 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		painting_map(t_tool *tool)
{
	int	j_tmp;
	int	i_tmp;

	tool->paint_i = 0;
	while (tool->paint_i < tool->c_rows - 1)
	{
		tool->paint_j = 0;
		while (tool->paint_j < tool->c_colum - 1)
		{
			uncle_brezenheim(tool, tool->aray[tool->paint_i][tool->paint_j],
			tool->aray[tool->paint_i][tool->paint_j + 1]);
			uncle_brezenheim(tool, tool->aray[tool->paint_i][tool->paint_j],
			tool->aray[tool->paint_i + 1][tool->paint_j]);
			tool->paint_j++;
		}
		j_tmp = tool->paint_j;
		tool->paint_i++;
		i_tmp = tool->paint_i;
	}
	help_painting_map(tool, i_tmp, j_tmp);
}

void		help_painting_map(t_tool *tool, int i_tmp, int j_tmp)
{
	tool->k = 0;
	if (tool->c_rows > 1 && tool->c_colum > 1)
	{
		while (tool->k < tool->c_colum - 1)
		{
			uncle_brezenheim(tool, tool->aray[i_tmp][tool->k],
			tool->aray[i_tmp][tool->k + 1]);
			tool->k++;
		}
		tool->k = 0;
		while (tool->k < tool->c_rows - 1)
		{
			uncle_brezenheim(tool, tool->aray[tool->k][j_tmp],
			tool->aray[tool->k + 1][j_tmp]);
			tool->k++;
		}
	}
}

void		proc_if(t_tool *tool, t_coord c1, t_coord c2)
{
	tool->i_if = 1;
	help_if(tool, c1, c2);
	mlx_pixel_put(tool->mlx, tool->win, c1.x, c1.y, 0x00ffcb);
	while (tool->i_if <= tool->delta_x)
	{
		if (tool->d_if > 0)
		{
			tool->d_if += tool->d2_if;
			tool->y_if += tool->sign_y;
		}
		else
			tool->d_if += tool->d1_if;
		mlx_pixel_put(tool->mlx, tool->win,
		tool->x_if, tool->y_if, 0x00ffcb);
		tool->x_if += tool->sign_x;
		tool->i_if++;
	}
}

void		proc_else(t_tool *tool, t_coord c1, t_coord c2)
{
	tool->i_else = 0;
	help_else(tool, c1, c2);
	mlx_pixel_put(tool->mlx, tool->win, c1.x, c1.y, 0x00ffcb);
	while (tool->i_else <= tool->delta_y)
	{
		if (tool->d_else > 0)
		{
			tool->d_else += tool->d2_else;
			tool->x_else += tool->sign_x;
		}
		else
			tool->d_else += tool->d1_else;
		mlx_pixel_put(tool->mlx, tool->win, tool->x_else,
		tool->y_else, 0x00ffcb);
		tool->i_else++;
		tool->y_else += tool->sign_y;
	}
}

void		uncle_brezenheim(t_tool *tool, t_coord c1, t_coord c2)
{
	c1.x = c1.x * 20 + 500;
	c1.y = c1.y * 20 + 500;
	c2.x = c2.x * 20 + 500;
	c2.y = c2.y * 20 + 500;
	help_uncle(tool, c1, c2);
	if (tool->delta_y <= tool->delta_x)
		proc_if(tool, c1, c2);
	else
		proc_else(tool, c1, c2);
}
