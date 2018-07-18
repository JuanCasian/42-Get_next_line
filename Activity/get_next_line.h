/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:15:34 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/17 20:48:44 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include "libft/libft.h"

typedef	struct		s_elem
{
	char			*str;
	int				fd;
	struct s_elem	*next;
}					t_elem;

int					get_next_line(const int fd, char **line);

#endif
