/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:55:21 by vnicoles          #+#    #+#             */
/*   Updated: 2024/05/23 11:13:17 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	joined_string = (char *) malloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (!joined_string)
		return (NULL);
	while (s1[i])
	{
		joined_string[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		joined_string[j] = s2[i];
		i++;
		j++;
	}
	joined_string[j] = '\0';
	return (joined_string);
}

size_t	ft_strlen(const char *a)
{
	size_t	len;

	len = 0;
	while (a[len])
		len++;
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *haystack, int c)
{
	int		index;
	char	needle;

	needle = (char) c;
	index = 0;
	while (haystack[index] != '\0')
	{
		if (haystack[index] == needle)
			return ((char *) &haystack[index]);
		index++;
	}
	if (haystack[index] == needle)
		return ((char *) &haystack[index]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
