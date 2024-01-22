/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:26:59 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/20 18:26:05 by avelikan         ###   ########.fr       */
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if ((size > 0) && (count > 0) && (count > (SIZE_MAX / size)))
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *) ptr)[i] = 0;
		i++;
	}
	return (ptr);
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
	int		i;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	s3 = malloc(l1 + l2 + 1);
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[i - l1] != '\0')
	{
		s3[i] = s2[i - l1];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
