/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:00:43 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/25 22:13:39 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*str;
	int		ret;

	str = NULL;
	ret = 1;
	fd = open("test.txt", O_RDONLY);
	// ret = get_next_line(fd, &str);
	// printf("%s\n", str);
	//ret = get_next_line(fd, &str);
	//printf("%s\n", str);
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		printf("%s\n", str);
		//free(str);
	}
	return (0);
}

// int main()
// {
// 	char	*line;
// 	int		ret;

// 	ret = 1;
// 	while (ret > 0)
// 	{
// 		ret = get_next_line(0, &line);
// 		printf("%s\n", line);
// 	}
// 	return (0);
// }
