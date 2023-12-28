/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:19:06 by yokten            #+#    #+#             */
/*   Updated: 2023/01/25 11:18:08 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*to_return;
	int		s1_len;
	int		s2_len;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		*s1 = '\0';
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	to_return = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!to_return)
		return (0);
	ft_strcpy(to_return, s1, s1_len);
	ft_strcpy(to_return + s1_len, s2, s2_len + 1);
	free(s1);
	return (to_return);
}

char	*ft_strcpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
