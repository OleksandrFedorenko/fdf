/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:04:11 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/20 11:36:07 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *a;
	t_list *b;

	a = *alst;
	while (a)
	{
		b = a->next;
		del(a->content, a->content_size);
		free(a);
		a = b;
	}
	*alst = NULL;
}
