/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:24:49 by vnicoles          #+#    #+#             */
/*   Updated: 2024/02/14 13:50:26 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src_char;
	char	*dest_char;
	char	*temp;
	int		i;

	i = 0;
	*src_char = (char *)src;
	*dest_char = (char *)dest;
	*temp = (char *)malloc(sizeof(char *) * n);
	while (i < n)
	{
		temp[i] = src_char[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_char[i] = temp[i];
		i++;
	}
	free(temp);
	return (dest);
}
