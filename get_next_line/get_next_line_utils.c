/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:26:59 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/19 11:27:03 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (unsigned char) c;
	if (ch == '\0')
	{
		return ((char *)(s + ft_strlen(s)));
	}
	while (*s)
	{
		if (ch == *s)
			return ((char *) s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		l;
	int		i;
	char	*s1_dup;

	i = 0;
	l = ft_strlen(s1);
	s1_dup = (char *) malloc(l + 1);
	if (s1_dup == 0)
		return (NULL);
	while (i < l)
	{
		s1_dup[i] = s1[i];
		i++;
	}
	s1_dup[i] = '\0';
	return (s1_dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s3 = (char *) malloc((l1 + l2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, l1 + l2 + 1);
	ft_strlcat(s3, s2, l1 + l2 + 1);
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_sub;
	size_t	s_len;
	size_t	tail;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	tail = 0;
	if (start < s_len)
		tail = s_len - start;
	if (tail > len)
		tail = len;
	s_sub = (char *) malloc((tail + 1) * sizeof(char));
	if (!s_sub)
		return (NULL);
	if (start >= s_len)
	{
		*s_sub = '\0';
		return (s_sub);
	}
	ft_strlcpy(s_sub, s + start, tail + 1);
	return (s_sub);
}
