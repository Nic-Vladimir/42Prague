/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:00:16 by vnicoles          #+#    #+#             */
/*   Updated: 2024/02/26 17:28:51 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	little_len = 0;
	while (*little != '\0')
	{
		little++;
		little_len++;
	}
	while (len > 0 && *big != '\0')
	{
		i = 0;
		while (i < little_len && i < len && big[i] == little[i])
		{
			i++;
		}
		if (i == little_len)
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
