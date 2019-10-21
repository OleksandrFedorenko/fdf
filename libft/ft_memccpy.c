/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:42:39 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/14 17:42:41 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = ((unsigned char*)dst);
	src1 = ((unsigned char*)src);
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == ((unsigned char)c))
			return (dst1 + i + 1);
		i++;
	}
	return (NULL);
}
