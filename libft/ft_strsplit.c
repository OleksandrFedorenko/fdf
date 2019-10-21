/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:32:36 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/23 12:15:02 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *str, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	if (!str)
		return (NULL);
	if (!(result = (char **)malloc(sizeof(char*) * (countw(str, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < countw(str, c))
	{
		j = 0;
		while (str[k] == c && str[k] != '\0')
			k++;
		if (!(result[i] = (char*)malloc(sizeof(char) * counts(str, c, k) + 1)))
			return (NULL);
		while (str[k] != c && str[k] != '\0')
			result[i][j++] = str[k++];
		result[i][j] = '\0';
		i++;
	}
	result[countw(str, c)] = NULL;
	return (result);
}
