/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:37:31 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/29 00:39:45 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void exit_with_error(const char *message, int exit_code)
{
    write(2, message, strlen(message));
    write(2, "\n", 1);
    exit(exit_code);
}

unsigned int ft_atoui(const char *num)
{
    unsigned int    res;
    int             i;

    i = 0;
    res = 0;
    while (num[i])
    {
        if (res > (UINT_MAX / 10) || (res == (UINT_MAX / 10) && ((unsigned int)num[i] - '0') > (UINT_MAX % 10)))
            exit_with_error("Pass numbers smaller than 4.294.967.295", 1);
        res = res * 10 + (num[i] - '0');
        i++;
    }
    return res;
}
