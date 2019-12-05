/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:13 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/04 17:22:44 by vmoreau          ###   ########.fr       */
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
	free(s1);
	return (join);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dup != NULL)
	{
		while (str[i] != '\0')
		{
			dup[i] = str[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}

char	*ft_take_end(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i++;
	while (str[i] != '\0')
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_cut_end(char *str)
{
	int		len;
	int		i;
	char	*tmp;

	len = 0;
	i = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp != NULL)
	{
		while (i < len && str[i] != '\0')
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
