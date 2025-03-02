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

uint64_t get_current_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000 + ts.tv_nsec / 1e6;
}

uint64_t get_curr_sim_time(void *arg)
{
    t_philo_data    *data;

    data = (t_philo_data *)arg;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    uint64_t now = (ts.tv_sec * 1000) + (ts.tv_nsec / 1e6);
    return (now - data->start_time);
}

void init_sim_time(void *arg)
{
    t_philo_data    *data;

    data = (t_philo_data *)arg;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    data->start_time = (ts.tv_sec * 1000) + (ts.tv_nsec / 1e6);
}

void    *overseer(void *arg)
{
    t_philo_data    *data;
    uint64_t        delta_time;
    uint64_t        curr_time;
    unsigned int    i;
    unsigned int    philos_have_eaten;

    data = (t_philo_data *)arg;
    i = 0;
    while (1)
    {
        philos_have_eaten = 0;
        pthread_mutex_lock(&data->sim_end_mutex);
        if (data->sim_end) {
            pthread_mutex_unlock(&data->sim_end_mutex);
            return NULL; // Exit the overseer thread
        }
        pthread_mutex_unlock(&data->sim_end_mutex);
        while (i < data->num_philo)
        {
            if (data->num_meals != -1 && data->philos[i].times_eaten >= (unsigned int)data->num_meals) {
                philos_have_eaten++;
                if (philos_have_eaten == data->num_philo) {
                    curr_time = get_curr_sim_time(data);
                    pthread_mutex_lock(&data->printf_mutex);
                    printf("%"PRIu64" Philosophers ate %u times. End sim.\n", curr_time, data->num_meals);
                    pthread_mutex_unlock(&data->printf_mutex);
                    pthread_mutex_lock(&data->sim_end_mutex);
                    data->sim_end = true;
                    pthread_mutex_unlock(&data->sim_end_mutex);
                }
            }
            curr_time = get_curr_sim_time(data);
            pthread_mutex_lock(&data->philos[i].last_eaten_mutex);
            printf("\ncurrent time: %"PRIu64"\nlast spaghett of [%u]: %"PRIu64" starvation: %u \n", curr_time, i, curr_time-data->philos[i].last_eaten, data->time_to_die);
            delta_time = curr_time - data->philos[i].last_eaten;
            pthread_mutex_unlock(&data->philos[i].last_eaten_mutex);
            if (delta_time > data->time_to_die)
            {
                pthread_mutex_lock(&data->printf_mutex);
                printf("%"PRIu64" Philosopher [%u] dieded\n", curr_time, data->philos[i].id);
                pthread_mutex_unlock(&data->printf_mutex);
                pthread_mutex_lock(&data->sim_end_mutex);
                data->sim_end = true;
                pthread_mutex_unlock(&data->sim_end_mutex);
                return NULL;
            }
            i++;
        }
        usleep(4000);
        i = 0;
    }
}

static void check_args(char **argv)
{
    int i;
    int j;

    j = 0;
    i = 1;
    while(argv[i] != NULL)
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
    unsigned int    i;

    i = 0;
    t_philo_data    *data = NULL;

    data = (t_philo_data *)malloc(sizeof(t_philo_data));
    if (!data)
        exit_with_error("Malloc failed", 1);
    data->num_philo = ft_atoui(argv[1]);
    data->time_to_die = ft_atoui(argv[2]);
    data->time_to_eat = ft_atoui(argv[3]);
    data->time_to_sleep = ft_atoui(argv[4]);
    data->sim_end = false;
    if (argv[5] != NULL)
        data->num_meals = ft_atoui(argv[5]);
    else
        data->num_meals = -1;
    pthread_mutex_init(&data->printf_mutex, NULL);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
    while (i < data->num_philo)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    i = 0;
    data->philos = malloc(sizeof(t_philo) * data->num_philo);
    init_sim_time(data);
    while (i < data->num_philo)
    {
        data->philos[i].id = i;
        data->philos[i].left_fork = &data->forks[i];
        data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philo];
        data->philos[i].data = data;
        data->philos[i].last_eaten = 0;
        data->philos[i].times_eaten = 0;
        pthread_mutex_init(&data->philos[i].last_eaten_mutex, NULL);
        i++;
    }
    return (data);
}

void    *philosopher_routine(void   *arg)
{
    t_philo         *philo;
    t_philo_data    *data;
    int             can_eat;

    can_eat = 1;
    philo = (t_philo *)arg;
    data = philo->data;
    while (1)
    {
        // THINKING
        pthread_mutex_lock(&data->printf_mutex);
        printf("%"PRIu64" Philosopher [%u] is thinking\n", get_curr_sim_time(data), philo->id);
        pthread_mutex_unlock(&data->printf_mutex);
        // EATING
        if (data->num_philo == 1)
        {
            pthread_mutex_lock(philo->right_fork);
            pthread_mutex_lock(&data->printf_mutex);
            printf("%"PRIu64" Philosopher [%u] has taken a fork %u\n", get_curr_sim_time(data), philo->id, philo->id);
            pthread_mutex_unlock(&data->printf_mutex);
            can_eat = 0;
        }
        else if (philo->id % 2 == 0)
        {
            pthread_mutex_lock(philo->right_fork);
            pthread_mutex_lock(philo->left_fork);
        }
        else
        {
            pthread_mutex_lock(philo->left_fork);
            pthread_mutex_lock(philo->right_fork);
        }
        if (can_eat)
        {
            pthread_mutex_lock(&data->printf_mutex);
            printf("%"PRIu64" Philosopher [%u] has taken forks %u and %u\n", get_curr_sim_time(data), philo->id, philo->id, (philo->id + 1));
            printf("%"PRIu64" Philosopher [%u] is eating\n", get_curr_sim_time(data), philo->id);
            pthread_mutex_unlock(&data->printf_mutex);
            pthread_mutex_lock(&philo->last_eaten_mutex);
            pthread_mutex_lock(&philo->times_eaten_mutex);
            philo->last_eaten = get_curr_sim_time(data);
            philo->times_eaten++;
            pthread_mutex_unlock(&philo->times_eaten_mutex);
            pthread_mutex_unlock(&philo->last_eaten_mutex);
            usleep(data->time_to_eat * 1000);
            pthread_mutex_unlock(philo->left_fork);
            pthread_mutex_unlock(philo->right_fork);
        }
        else if (!can_eat)
        {
            pthread_mutex_unlock(philo->right_fork);
            usleep(data->time_to_die * 2);
            can_eat = 1;
        }
        // SLEEPING
        pthread_mutex_lock(&data->printf_mutex);
        printf("%"PRIu64" Philosopher [%u] is sleeping\n", get_curr_sim_time(data), philo->id);
        pthread_mutex_unlock(&data->printf_mutex);
        usleep(data->time_to_sleep * 1000);

        pthread_mutex_lock(&data->sim_end_mutex);
        if (data->sim_end)
        {
            pthread_mutex_unlock(&data->sim_end_mutex);
            return NULL;
        }
        pthread_mutex_unlock(&data->sim_end_mutex);
    }
}

int	main(int argc, char **argv)
{
    pthread_t       overseer_thread;
    t_philo_data    *data;
    unsigned int    i;

    i = 0;
    if (argc != 5 && argc != 6)
        return(write(1, "Usage: ./philo <num_philo> <time_to_die_ms> <time_to_eat_ms> <time_to_sleep_ms> [number_of_times_each_philosopher_must_eat]\n", 80), 1);
    check_args(argv);
    data = init_philo_data(argv);
    while (i < data->num_philo)
    {
        if (pthread_create(&data->philos[i].thread, NULL, &philosopher_routine, &data->philos[i]) != 0)
            exit_with_error("Failed to create thread", 1);
        i++;
    }
    pthread_create(&overseer_thread, NULL, overseer, data);
    i = 0;
    while (i < data->num_philo)
    {
        if (pthread_join(data->philos[i].thread, NULL) != 0)
            exit_with_error("Failed to join thread", 1);
        i++;
    }
    pthread_join(overseer_thread, NULL);
    pthread_mutex_destroy(&data->sim_end_mutex);
    pthread_mutex_destroy(&data->printf_mutex);
    for (unsigned int i = 0; i < data->num_philo; i++) {
        pthread_mutex_destroy(&data->forks[i]);
        pthread_mutex_destroy(&data->philos[i].last_eaten_mutex);
    }
    free(data->forks);
    free(data->philos);
    free(data);
	return (0);
}

