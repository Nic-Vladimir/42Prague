/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:02:18 by vnicoles          #+#    #+#             */
/*   Updated: 2024/02/12 21:08:54 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_memcpy(void *dest, void *src, size_t n) {
	int	i;
	char	*src_char;
	char	*dest_char;

	i = 0;
	*src_char = (char *)src;
	*dest_char = (char *)dest;
	while (i < n) {
		dest_char[i] = src_char[i];
		i++;
	}
}
