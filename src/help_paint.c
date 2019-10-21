/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:04:14 by afedoren          #+#    #+#             */
/*   Updated: 2018/10/29 12:04:17 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		help_else(t_tool *tool, t_coord c1, t_coord c2)
{
	tool->d_else = (tool->delta_x << 1) - tool->delta_y;
	tool->d1_else = tool->delta_x << 1;
	tool->d2_else = (tool->delta_x - tool->delta_y) << 1;
	tool->x_else = c1.x;
	tool->y_else = c1.y + tool->sign_y;
}

void		help_if(t_tool *tool, t_coord c1, t_coord c2)
{
	tool->d_if = (tool->delta_y << 1) - tool->delta_x;
	tool->d1_if = tool->delta_y << 1;
	tool->d2_if = (tool->delta_y - tool->delta_x) << 1;
	tool->x_if = c1.x + tool->sign_x;
	tool->y_if = c1.y;
}

void		help_uncle(t_tool *tool, t_coord c1, t_coord c2)
{
	tool->delta_x = ft_abs(c2.x - c1.x);
	tool->delta_y = ft_abs(c2.y - c1.y);
	tool->sign_x = c1.x < c2.x ? 1 : -1;
	tool->sign_y = c1.y < c2.y ? 1 : -1;
	tool->error = tool->delta_x - tool->delta_y;
}
