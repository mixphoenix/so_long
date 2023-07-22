/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 03:51:17 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/22 03:51:17 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*gnl_strjoin(char const *s2, char const *s1)
{
	char	*constr;
	int		i;
	int		j;
	int		len;

	len = 0;
	len = gnl_strlen(s1) + 1;
	if (s2)
		len += gnl_strlen(s2);
	constr = malloc(len * sizeof(char));
	i = 0;
	j = 0;
	if (!constr)
		return (NULL);
	if (s2)
	{
		while (s2[j] != '\0')
			constr[i++] = s2[j++];
	}
	j = 0;
	while (s1[j] != '\0')
		constr[i++] = s1[j++];
	constr[i] = '\0';
	return (constr);
}

char	*gnl_strdup(char *src)
{
	int		i;
	int		x;
	char	*p;

	i = 0;
	x = gnl_strlen(src) + 1;
	if (!src)
		return (NULL);
	p = (char *)malloc(x * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substring;

	if (!s)
		return (NULL);
	s_len = gnl_strlen(s);
	if (start >= s_len)
		return (gnl_strdup(""));
	if (len > s_len || (s_len - start) < len)
		len = s_len - start;
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (s[start + i] && start + i < gnl_strlen(s) && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
