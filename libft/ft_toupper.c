/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:07:05 by vnicoles          #+#    #+#             */
/*   Updated: 2024/02/26 13:48:37 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

// int	main(void)
// {
// 	int	c;
// 	int	answer;

// 	c = 'k';
// 	answer = ft_toupper(c);
// 	write(1, &answer, 1);
// 	return (0);
// }