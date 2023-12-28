/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:19:03 by yokten            #+#    #+#             */
/*   Updated: 2023/01/25 11:18:14 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *stash)
{
	int		check;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	check = 1;
	while (check != 0 && (!ft_strchr(stash)))
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[check] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*ft_before_next_line(char *stash)
{
	char	*to_return;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	to_return = malloc(sizeof(char) * (i + 2));
	if (!to_return)
		return (NULL);
	ft_strcpy(to_return, stash, i + 1);
	return (to_return);
}

char	*ft_new_line(char *stash)
{
	char	*to_return;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	to_return = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!to_return)
		return (NULL);
	i++;
	ft_strcpy(to_return, stash + i, ft_strlen(stash + i));
	free(stash);
	return (to_return);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_file(fd, stash);
	if (!stash)
		return (NULL);
	to_return = ft_before_next_line(stash);
	stash = ft_new_line(stash);
	return (to_return);
}
