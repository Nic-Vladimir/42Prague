/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:14:16 by vnicoles          #+#    #+#             */
/*   Updated: 2024/02/14 14:25:48 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	int	dest_len;
	int	src_len;
	int	offset;
	int	src_index;

	dest_len = strlen(dest);
	src_len = strlen(src);
	offset = dest_len;
	src_index = 0;
	while (*(src + src_index) != '\0')
	{
		*(dest + offset) = *(src + src_index);
		offset++;
		src_index++;
		if (offset == destsize - 1)
			break ;
	}
	*(dest + offset) = '\0';
	return (dest_len + src_len);
}
