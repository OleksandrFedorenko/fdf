/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:08:51 by afedoren          #+#    #+#             */
/*   Updated: 2017/10/28 16:08:53 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			a;
	unsigned char	*b;
	unsigned char	*c;

	a = 0;
	b = (unsigned char*)s1;
	c = (unsigned char*)s2;
	while (a < n)
	{
		if (*b != *c)
			return (*b - *c);
		if (!*b && !*c)
			return (0);
		a++;
		b++;
		c++;
	}
	return (0);
}
