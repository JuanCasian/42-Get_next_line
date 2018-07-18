/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:55:16 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/17 21:00:55 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd[10];
	int		i;
	char	*str;
	int		res;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if ((fd[i] = open(av[i], O_RDONLY)) < 0)
			{
				ft_putendl("Error openning file");
				return (-1);
			}
			res = get_next_line(fd[i], &str);
			ft_putendl(str);
			res = get_next_line(fd[i], &str);
			ft_putendl(str);
			res = get_next_line(fd[i], &str);
			ft_putendl(str);
		i++;
		}
		i--;
		while (i > 0)
		{
			res = get_next_line(fd[i], &str);
			ft_putendl(str);
			res = get_next_line(fd[i], &str);
			ft_putendl(str);
		i--;
		}

	}

	return (0);
}
