/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:20:31 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/15 12:20:33 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function recieves a file descriptor and returns a string containing
** the information of the file. If the file was blank it returns NULL;
** In case of error exits the program and prints error reading file.
*/

#include "libft.h"

char	*ft_filetostr(int fd)
{
	char	buf[BUFSIZE];
	int		n;
	char	*str;
	size_t	len;

	len = 0;
	str = NULL;
	while ((n = read(fd, buf, BUFSIZE)))
	{
		if (n < 0)
		{
			ft_putendl_fd("Error reading file", 2);
			exit(EXIT_FAILURE);
		}
		str = (char*)ft_remalloc((void*)str, len + n + 1, len);
		str = (char*)ft_memcpy(str + len, buf, n);
		len += n;
		str[len] = '\0';
	}
	return (str);
}
