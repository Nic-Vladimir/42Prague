/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:59:20 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/03 06:22:34 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static char	*g_msg;

static void	cleanup(int sig)
{
	(void)sig;
	if (g_msg)
		free(g_msg);
	ft_printf("\nServer shutting down...\n");
	exit(0);
}

static char	*resize_buffer(char *old_msg, size_t old_size)
{
	char	*new_msg;

	new_msg = ft_calloc(old_size + old_size, sizeof(char));
	if (!new_msg)
	{
		free(old_msg);
		ft_printf("Memory allocation failed in resize_buffer.\n");
		exit(1);
	}
	ft_memcpy(new_msg, old_msg, old_size);
	free(old_msg);
	return (new_msg);
}

static int	process_message(siginfo_t *info, size_t i, size_t *capacity)
{
	if (g_msg[i] == '\0')
	{
		ft_printf("%s\n", g_msg);
		ft_memset(g_msg, 0, 10);
		kill(info->si_pid, SIGUSR2);
		*capacity = 10;
		return (0);
	}
	else
		i++;
	return (i);
}

static void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int		bit;
	static size_t	i;
	static size_t	capacity = 10;

	(void)context;
	if (!g_msg)
	{
		g_msg = ft_calloc(capacity, sizeof(char));
		if (!g_msg)
			exit(1);
	}
	if (i >= capacity - 1)
	{
		g_msg = resize_buffer(g_msg, capacity);
		capacity += capacity;
	}
	if (sig == SIGUSR1)
		g_msg[i] |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		i = process_message(info, i, &capacity);
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
	{
		ft_printf("Usage: ./server\n");
		return (1);
	}
	(void)argv;
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, &cleanup);
	ft_printf("Server PID: %d\n", getpid());
	while (argc == 1)
	{
		pause();
	}
	return (0);
}
