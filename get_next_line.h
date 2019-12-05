/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:25 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/03 18:48:35 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
**PROTOTYPE
*/
int				get_next_line(int fd, char **line);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_cut_end(char *str);
char			*ft_take_end(char *str);
int				stop_read(char *str);
char			*ft_strdup(char *str);
void			ft_free(char **str);
#endif
