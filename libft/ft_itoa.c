/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:27:59 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/15 14:28:01 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*area;
	int				len;
	unsigned int	num;

	len = 0;
	len = ft_count_int_extra5(n);
	if (!(area = (char *)malloc((len + 1))))
		return (0);
	area[len--] = '\0';
	num = ft_int_min_extra4(n);
	while (len >= 0)
	{
		area[len--] = num % 10 + 48;
		num = num / 10;
	}
	if (n < 0)
		area[0] = '-';
	return (area);
}
