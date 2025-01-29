/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:19:58 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/29 01:31:38 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <pthread.h>

static void check_args(char **argv)
{
    int i;
    int j;

    j = 0;
    i = 1;
    while(i < EXPECTED_ARGS)
    {
        if (argv[i][0] == '0' && argv[i][1] != '\0')
            exit_with_error("No leading zeros allowed", 1);
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                exit_with_error("Pass only positive numeric values", 1);
            j++;
        }
        ft_atoui(argv[i]);
        j = 0;
        i++;
    }
}

static t_philo_data  *init_philo_data(char **argv)
{
    t_philo_data    *philo_data = NULL;

    philo_data = (t_philo_data *)malloc(sizeof(t_philo_data));
    if (!philo_data)
        exit_with_error("Malloc failed", 1);
    philo_data->num_philo = ft_atoui(argv[1]);
    philo_data->num_forks = ft_atoui(argv[1]);
    philo_data->time_to_die = ft_atoui(argv[2]);
    philo_data->time_to_eat = ft_atoui(argv[3]);
    philo_data->time_to_sleep = ft_atoui(argv[4]);
    philo_data->dummy_sum = 0;
    pthread_mutex_init(&philo_data->mutex, NULL);
    return (philo_data);
}

void    *routine(void   *arg)
{
    t_philo_data    *philo_data = (t_philo_data *)arg;

    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&philo_data->mutex);
        philo_data->dummy_sum++;
        pthread_mutex_unlock(&philo_data->mutex);
    }
    return NULL;
}

int	main(int argc, char **argv)
{
    pthread_t       *philo_threads;
    t_philo_data    *philo_data;
    unsigned int    i;

    i = 0;
    if (argc != 5)
        return(write(1, "Usage: ./philo <num_philo> <time_to_die_ms> <time_to_eat_ms> <time_to_sleep_ms>\n", 71), 1);
    check_args(argv);
    philo_data = init_philo_data(argv);
    if (!(philo_threads = malloc(sizeof(pthread_t) * philo_data->num_philo)))
        exit_with_error("Memory allocation failed", 1);
    while (i < philo_data->num_philo)
    {
        if (pthread_create(&philo_threads[i], NULL, &routine, philo_data) != 0)
            exit_with_error("Failed to create thread", 1);
        printf("Philosopher %u has started counting...\n", i);
        i++;
    }
    i = 0;
    while (i < philo_data->num_philo)
    {
        if (pthread_join(philo_threads[i], NULL) != 0)
            exit_with_error("Failed to join thread", 1);
        printf("Philosopher %u has finished counting!\n", i);
        i++;
    }
    printf("End sum: %u\n", philo_data->dummy_sum);

    pthread_mutex_destroy(&philo_data->mutex);
    free(philo_data);
    free(philo_threads);
	return (0);
}

