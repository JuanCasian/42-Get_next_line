/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:30:24 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/19 16:28:05 by jcasian          ###   ########.fr       */
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
		if (str)
			free(str);
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
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = -1;
	while (elem->str[i] != '\n' && elem->str[i])
		i++;
	if (!(tmp = (char*)malloc(sizeof(char) * i + 1)))
		return (-1);
	while (++j < i)
		tmp[j] = elem->str[j];
	tmp[j] = '\0';
	*line = tmp;
	free(tmp);
	while (i-- > 0)
		elem->str++;
	if (!(elem->str[0]) && !(**line))
		return (0);
	elem->str++;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_elem	*list;
	t_elem			*curr;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (list)
		if ((curr = known_fd(list, fd)))
			return (get_str(curr, line));
	if (add_new_elem(&list, fd) == 0)
		return (-1);
	return (get_next_line(fd, line));
}
