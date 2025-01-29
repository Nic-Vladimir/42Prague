/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:25:49 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/29 01:05:08 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <limits.h>
#include <pthread.h>
#include <stdalign.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define EXPECTED_ARGS 5

typedef struct s_philo_data {
  unsigned int num_philo;
  unsigned int num_forks;
  unsigned int time_to_die;
  unsigned int time_to_eat;
  unsigned int time_to_sleep;
  pthread_mutex_t mutex;
  unsigned int dummy_sum;
} t_philo_data;

void exit_with_error(const char *message, int exit_code);
unsigned int ft_atoui(const char *num);

#endif
