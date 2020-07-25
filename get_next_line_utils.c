/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:50:19 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/15 18:59:07 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str)
		while (str[i] != 0)
			i++;
	return (i);
}

char		*ft_strdup_err(char *s1, int *err)
{
	char	*copy;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if (!(copy = malloc(len + 1)))
	{
		*err = -1;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char		*ft_strjoin_err(char *s1, char *s2, int *err)
{
	char	*news;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(news = ft_calloc_err(err, sizeof(char), (len_s1 + len_s2 + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			news[i] = s1[i];
		else
			news[i] = s2[j++];
		i++;
	}
	news[i] = '\0';
	return (news);
}

void		*ft_calloc_err(int *err, size_t count, size_t size)
{
	char	*s;
	char	*ps;
	size_t	i;

	if (!(s = malloc(size * count)))
	{
		*err = -1;
		return (NULL);
	}
	i = 0;
	ps = s;
	while (i != (size * count))
		ps[i++] = '\0';
	return (s);
}

char		*ft_strnew_err(size_t size, int *err)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
	{
		*err = -1;
		return (NULL);
	}
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}
