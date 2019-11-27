/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:00:43 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/27 17:17:14 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*str;
	int		ret;
	int		round = 1;

	str = NULL;
	ret = 1;
	fd = open("normal.txt", O_RDONLY);
	// ret = get_next_line(fd, &str);
	// printf("%s\n", str);
	while (ret > 0)
	{
		ret = get_next_line(4242, &str);
		printf("%d=\"%s\"\n",round, str);
		round++;
		free(str);
	}
	return (0);
}
