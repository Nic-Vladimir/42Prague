/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:01:38 by vnicoles          #+#    #+#             */
/*   Updated: 2024/02/26 14:31:42 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchar(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			last = &s[i];
		}
		i++;
	}
	return (last);
}
