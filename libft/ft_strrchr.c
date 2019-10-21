/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:40:11 by afedoren          #+#    #+#             */
/*   Updated: 2017/10/31 18:40:13 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char tmp;

	tmp = ((char)c);
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (*s != '\0')
		s++;
	while (*s != tmp)
	{
		s--;
	}
	return ((char *)s);
}
