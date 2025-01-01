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

static void ft_handler(int sig, siginfo_t *info, void *context)
{
    static int  bit;
    static char msg[10000];
    static int  i;

	(void)context;
    if (sig == SIGUSR1)
        msg[i] |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        if (msg[i] == '\0')
		{
            ft_printf("%s\n", msg);
			i = 0;
			ft_memset(msg, 0, sizeof(msg));
			kill(info->si_pid, SIGUSR2);
		}
		else
        	i++;
		bit = 0;
    }
	kill(info->si_pid, SIGUSR1);
}

int main(int argc, char **argv)
{
	struct sigaction sa;

    if (argc != 1)
    {
        ft_printf("Usage: ./server\n");
        return (1);
    }
    (void)argv;

	sa.sa_sigaction = ft_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    ft_printf("Server PID: %d\n", getpid());
    while (argc == 1)
    {
        pause();
    }
	return (0);
}

