/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:13 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/25 18:50:37 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		len;
	int		j;
	int		i;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_take_end(char *str, int ret)
{
	int		len;
	int		i;
	char	*end_str;

	i = 0;
	if (ret == 0)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i++;
	len = ft_strlen(str + i);
	end_str = (char *)malloc(sizeof(char) * (len + 1));
	if (end_str != NULL)
	{
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

char	*ft_cut_end(char *str)
{
	int		len;
	int		i;
	char	*tmp;

	len = 0;
	i = 0;
	if (stop_read(str) == 0)
		return (str);
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp != NULL)
	{
		while (i < len)
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
