/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:38:56 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/15 12:39:00 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char				*str;
	unsigned int		bg;
	unsigned int		end;

	if (s)
	{
		if (!*s)
			return (ft_strnew(1));
		bg = 0;
		end = ft_strlen(s) - 1;
		while ((s[bg] == ' ' || s[bg] == '\t' || s[bg] == '\n'
				|| s[bg] == '.') && bg < end + 1)
			bg++;
		while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n'
				|| s[end] == '.') && &s[end] != s)
			end--;
		if (bg >= end || bg == ft_strlen(s))
			return (ft_strnew(1));
		if ((str = ft_strnew(end - bg + 1)))
		{
			ft_strncpy(str, s + bg, end - bg + 1);
			return (str);
		}
	}
	return (NULL);
}
