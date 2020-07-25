/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:58:23 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/15 18:58:34 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

char			*ft_strcpy(char *dest, char *src)
{
	int			i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strchr(const char *s, int c)
{
	int			i;
	char		*ps;

	i = 0;
	ps = (char *)s;
	while (ps[i] != (char)c)
	{
		if (ps[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&ps[i]);
}

char			*root_order(char *root, char **line, int *err)
{
	char		*p_x;

	*err = 1;
	if (!(line))
		*err = -1;
	p_x = NULL;
	if (root)
	{
		if ((p_x = ft_strchr(root, '\n')))
		{
			*p_x = '\0';
			*line = ft_strdup_err(root, err);
			p_x++;
			ft_strcpy(root, p_x);
		}
		else
		{
			*line = ft_strdup_err(root, err);
			ft_strclr(root);
		}
	}
	else if (*err != -1)
		*line = ft_strnew_err(1, err);
	return (p_x);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*root;
	char		*p_buf;
	char		*delx;
	int			err;

	if ((read(fd, NULL, 0) == -1) || (BUFFER_SIZE < 1))
		return (-1);
	p_buf = root_order(root, line, &err);
	while (!p_buf && err != -1 && (err = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[err] = '\0';
		if ((p_buf = ft_strchr(buf, '\n')))
		{
			*p_buf++ = '\0';
			free(root);
			root = ft_strdup_err(p_buf, &err);
		}
		delx = *line;
		*line = ft_strjoin_err(*line, buf, &err);
		free(delx);
	}
	if (err == -1)
		return (-1);
	return (ft_strlen(root) || err) ? 1 : 0;
}
