/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:04:14 by vnicoles          #+#    #+#             */
/*   Updated: 2024/12/20 12:32:38 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void    ft_chartobits(int pid, char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if (c & (0x01 << bit))
            kill(pid, SIGUSR1);
        else
        {
            kill(pid, SIGUSR2);
            usleep(500);
        }
        bit++;
    }
}

int main(int argc, char **argv)
{
    int     pid;
    int     i;

    i = 0;
    if (argc != 3)
    {
        ft_printf("Usage: ./client <pid> <message>\n");
        return (1);
    }
    pid = ft_atoi(argv[1]);
    while (argv[2][i] != '\0')
    {
        ft_chartobits(pid, argv[2][i]);
        i++;
    }
    ft_chartobits(pid, '\0');
    return (0);
}