/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:30:24 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/17 21:37:48 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *remalloc(void *ptr, size_t size, size_t curr)
{
        void    *newptr;

        if (!(newptr = (void*)malloc(size)))
                return (NULL);
        newptr = ft_memcpy(newptr, ptr, curr);
        return (newptr);
}

char	*read_file(int fd)
{
	char	buf[BUFF_SIZE];
	int		n;
	size_t	len;
	char	*str;
	int		flag;

	len = 0;
	str = NULL;
	flag = 0;
	while ((n = read(fd, buf, BUFF_SIZE)))
	{
		if (n < 0)
			return (NULL);
		str = (char*)remalloc((void*)str, len + n + 1, len);
		if (!str)
			return (NULL);
		str = (char*)ft_memcpy(&str[len], buf, n);
		len += n;
		flag++;
		str[len] = '\0';
	}
	if (!flag)
		return (NULL);
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

	i = 0;
	while (elem->str[i] && elem->str[i] != '\n')
		i++;
	if (!(*line = (char*)malloc(sizeof(char) * i + 1)))
		return (-1);
	i = 0;
	while (elem->str[i] && elem->str[i] != '\n')
	{
		*line[i] = elem->str[i];
		i++;
	}
	elem->str = elem->str + i;
	*line[i] = '\0';
	if (!(elem->str[0]))
		return (0);
	elem->str++;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_elem	*list;
	t_elem			*curr;

	if (list)
		if ((curr = known_fd(list, fd)))
			return (get_str(curr, line));
	if (add_new_elem(&list, fd) == 0)
		return (-1);
	return (get_next_line(fd, line));
}
