/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:44:03 by afedoren          #+#    #+#             */
/*   Updated: 2018/10/28 18:44:06 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	just_exit(void *param)
{
	(void)param;
	exit(0);
}

int		deal_key(int key, t_tool *tool)
{
	if (key == 53)
		just_exit((void *)0);
	return (0);
}
