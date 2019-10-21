/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:03:51 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/20 13:03:52 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstresult;
	t_list	*lstmove;

	if (lst && f)
	{
		lstresult = f(lst);
		lstmove = lstresult;
		while (lst->next != NULL)
		{
			lstmove->next = f(lst->next);
			lstmove = lstmove->next;
			lst = lst->next;
		}
		return (lstresult);
	}
	return (NULL);
}
