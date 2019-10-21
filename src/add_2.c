/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:43:11 by afedoren          #+#    #+#             */
/*   Updated: 2018/10/28 18:43:14 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_error(char *line)
{
	ft_putstr(line);
	write(1, "\n", 1);
	exit(0);
}

void		init_tool(t_tool *tool)
{
	tool->c_rows = 0;
	tool->c_colum = 0;
	tool->main_x = 0;
	tool->main_y = 0;
	tool->main_xx = 0;
	tool->main_yy = 0;
	tool->delta_x = 0;
	tool->delta_y = 0;
	tool->sign_x = 0;
	tool->sign_y = 0;
	tool->error = 0;
	tool->d_else = 0;
	tool->d1_else = 0;
	tool->d2_else = 0;
	tool->x_else = 0;
	tool->y_else = 0;
	tool->d_if = 0;
	tool->d1_if = 0;
	tool->d2_if = 0;
	tool->x_if = 0;
	tool->y_if = 0;
}
