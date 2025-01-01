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

static volatile sig_atomic_t g_sig_ack;

void    ft_sig_handler(int signum)
{
	if (signum == SIGUSR1)
		g_sig_ack = 1;
	else if (signum == SIGUSR2)
		ft_printf("Bogos Binted!\n");
}

void    ft_chartobits(int pid, char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
		g_sig_ack = 0;
        if (c & (0x01 << bit))
            kill(pid, SIGUSR1);
        else
        {
            kill(pid, SIGUSR2);
        }
		while (!g_sig_ack)
			pause();
        bit++;
		g_sig_ack = 0;
    }
}

int main(int argc, char **argv)
{
    int     pid;
    int     i;

    if (argc != 3)
    {
        ft_printf("Usage: ./client <PID> <message>\n");
        return (1);
    }
	i = 0;
    pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
    while (argv[2][i] != '\0')
    {
        ft_chartobits(pid, argv[2][i]);
        i++;
    }
    ft_chartobits(pid, '\0');
    return (0);
}
