/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:39:33 by bede-car          #+#    #+#             */
/*   Updated: 2022/07/19 16:35:15 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len_total;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = -1;
	len_s2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len_total = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new_str = malloc (len_total);
	if (!new_str)
		return (NULL);
	while (s1[++len_s1])
		new_str[len_s1] = s1[len_s1];
	while (s2[len_s2])
		new_str[len_s1++] = s2[len_s2++];
	new_str[len_s1] = '\0';
	return (new_str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while ((i + 1 < size) && src[i])
		{
			dst[i] = (char)src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(char *s)
{
	char	*strnew;
	size_t	sz;

	sz = (ft_strlen(s)+ 1);
	strnew = malloc(sz);
	if (!strnew)
		return (NULL);
	ft_strlcpy(strnew, s, sz);
	return (strnew);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	len_max;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		return (ft_strdup(""));
	if ((len_s - start) <= len)
		len_max = len_s - start;
	else
		len_max = len;
	sub = malloc(len_max + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len_max + 1);
	return (sub);
}
