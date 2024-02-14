/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:52:38 by vnicoles          #+#    #+#             */
/*   Updated: 2024/02/14 14:06:52 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	int	offset;

	offset = 0;
	if (destsize > 0)
	{
		while (*(src + offset) != '\0')
		{
			if (offset == destsize)
			{
				offset--;
				break ;
			}
			*(dest + offset) = *(src + offset);
			offset++;
		}
	}
	*(dest + offset) = '\0';
	while (*(src + offset) != '\0')
		offset++;
	return (offset);
}
