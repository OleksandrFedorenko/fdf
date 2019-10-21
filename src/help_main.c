/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:21:01 by afedoren          #+#    #+#             */
/*   Updated: 2018/10/28 19:21:08 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		y_transform(t_tool *tool)
{
	while (tool->main_y < tool->c_rows)
	{
		tool->main_x = 0;
		while (tool->main_x < tool->c_colum)
		{
			tool->aray[tool->main_y][tool->main_x].x =
			(tool->aray[tool->main_y][tool->main_x].x *
			(double)cos(0.50) + tool->aray[tool->main_y][tool->main_x].z *
			(double)sin(0.50));
			tool->aray[tool->main_y][tool->main_x].z =
			((-tool->aray[tool->main_y][tool->main_x].x) *
			(double)sin(0.50) + tool->aray[tool->main_y][tool->main_x].z *
			(double)cos(0.50));
			tool->main_x++;
		}
		tool->main_y++;
	}
}

void		x_transform(t_tool *tool)
{
	double	b;
	double	c;

	while (tool->main_yy < tool->c_rows)
	{
		tool->main_xx = 0;
		while (tool->main_xx < tool->c_colum)
		{
			b = tool->aray[tool->main_yy][tool->main_xx].y;
			c = tool->aray[tool->main_yy][tool->main_xx].z;
			tool->aray[tool->main_yy][tool->main_xx].y =
			(b * (double)cos(-1) + c * (double)sin(-1));
			tool->aray[tool->main_yy][tool->main_xx].z =
			(-(b) * (double)sin(-1) + c * (double)cos(-1));
			tool->main_xx++;
		}
		tool->main_yy++;
	}
}
