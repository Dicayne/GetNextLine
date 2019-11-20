/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:13 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/20 19:17:48 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_take_end(char *str)
{
	int len;
	int i;
	char *end_str;

	i = 0;
	while (str[i] != '\n')
		i++;
	len = ft_strlen(str + i);
	end_str = (char *)malloc(sizeof(char) * len);
	if (end_str != NULL)
	{
		i++;
		len = 0;
		while (str[i] != '\0')
		{
			end_str[len] = str[i];
			len++;
			i++;
		}
		end_str[len] = '\0';
	}
	return (end_str);
}