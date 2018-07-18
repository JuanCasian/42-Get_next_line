/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:30:24 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/18 14:07:44 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd)
{
	char	buf[BUFF_SIZE];
	char	*str;
	char	*nstr;
	int		n;
	size_t	len;

	str = NULL;
	len = 0;
	while ((n = read(fd, buf, BUFF_SIZE)))
	{
		if (n < 0)
			return (NULL);
		if (!(nstr = ft_strnew(len + n)))
			return (NULL);
		nstr = ft_strncat(nstr, str, len);
		nstr = ft_strncat(nstr, (char*)buf, n);
		free((void*)str);
		str = nstr;
		len += n;
	}
	return (str);
}

int		add_new_elem(t_elem **list, const int fd)
{
	t_elem	*new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (0);
	new->fd = (int)fd;
	new->str = read_file(fd);
	if (!(new->str))
		return (0);
	if (*list)
	{
		new->next = *list;
		*list = new;
	}
	else
	{
		new->next = NULL;
		*list = new;
	}
	return (1);
}

t_elem	*known_fd(t_elem *list, int fd)
{
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int		get_str(t_elem *elem, char **line)
{
	size_t		i;

	i = 0;
	while (elem->str[i] && elem->str[i] != '\n')
		i++;
	*line = NULL;
	if (!(*line = ft_strnew(i)))
		return (-1);
	i = 0;
	while (elem->str[i] && elem->str[i] != '\n')
	{
		line[0][i] = elem->str[i];
		i++;
	}
	elem->str = elem->str + i;
	line[0][i] = '\0';
	if (!(elem->str[0]) && !(**line))
		return (0);
	elem->str++;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_elem	*list;
	t_elem			*curr;

	if (fd < 0)
		return (-1);
	if (list)
		if ((curr = known_fd(list, fd)))
			return (get_str(curr, line));
	if (add_new_elem(&list, fd) == 0)
		return (-1);
	return (get_next_line(fd, line));
}
