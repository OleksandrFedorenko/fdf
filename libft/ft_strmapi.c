/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:10:08 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/13 11:28:57 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	int				i;
	unsigned int	index;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	if (!(fresh = (ft_strnew(ft_strlen(s)))))
		return (NULL);
	while (s[i] != '\0')
	{
		fresh[i] = (*f)(index, s[i]);
		index++;
		i++;
	}
	return (fresh);
}
