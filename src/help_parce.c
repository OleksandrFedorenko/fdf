/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_parce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:47:55 by afedoren          #+#    #+#             */
/*   Updated: 2018/10/28 18:47:58 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		make_list(t_line **head, char *line, t_tool *tool)
{
	t_line		*new;
	t_line		*temp;
	int			i;

	i = 0;
	new = (t_line*)ft_memalloc(sizeof(t_line));
	new->line = line;
	new->next = NULL;
	if (*head)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*head = new;
	tool->c_rows++;
}
