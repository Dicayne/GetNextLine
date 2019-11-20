/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:00:43 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/20 19:32:34 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*str;
	int		ret;

	ret = 1;
	fd = open("test.txt", O_RDONLY);
	// ret = get_next_line(fd, &str);
	// printf("TATA:%s\n\n%d\n", str, ret);
	// ret = get_next_line(fd, &str);
	// printf("TiTA:%s\n\n%d\n", str, ret);
	// ret = get_next_line(fd, &str);
	// printf("TiTA:%s\n\n%d\n", str, ret);
	// ret = get_next_line(fd, &str);
	// printf("TiTA:%s\n\n%d\n", str, ret);
	// ret = get_next_line(fd, &str);
	// printf("TiTA:%s\n\n%d\n", str, ret);
	// ret = get_next_line(fd, &str);
	// printf("TiTA:%s\n\n%d\n", str, ret);
	// ret = get_next_line(fd, &str);
	// printf("TiTA:%s\n\n%d\n", str, ret);
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		printf("%s\n",str);
	}
	return (0);
}
