/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:58:51 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/23 23:10:00 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

void	ft_strclr(char *s);
int		ft_strlen(char *str);
char	*ft_strdup_err(char *s1, int *err);
char	*ft_strjoin_err(char *s1, char *s2, int *err);
void	*ft_calloc_err(int *err, size_t count, size_t size);
char	*ft_strnew_err(size_t size, int *err);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(const char *s, int c);
char	*root_order(char *root, char **line, int *err);
int		get_next_line(int fd, char **line);

#endif
