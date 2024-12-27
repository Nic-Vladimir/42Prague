/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:59:20 by vnicoles          #+#    #+#             */
/*   Updated: 2024/12/20 13:12:56 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void ft_handler(int sig)
{
    static int  bit;
    static char msg[10000];
    static int  i;

    if (sig == SIGUSR1)
        msg[i] |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        if (msg[i] == '\0')
            ft_printf("%s\n", msg);
        i++;
        bit = 0;
    }
}

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        ft_printf("Usage: ./server\n");
        return (1);
    }
    (void)argv;
    ft_printf("Server PID: %d\n", getpid());

    while (argc == 1)
    {
        signal(SIGUSR1, ft_handler);
        signal(SIGUSR2, ft_handler);
        pause();
    }
}

