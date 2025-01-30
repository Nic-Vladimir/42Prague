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
#define __STDC_FORMAT_MACROS

#include <inttypes.h>
#include <limits.h>
#include <pthread.h>
#include <stdalign.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define EXPECTED_ARGS 5

typedef struct s_philo {
  int id;
  pthread_t thread;
  pthread_mutex_t *left_fork;
  pthread_mutex_t *right_fork;
  uint64_t last_eaten;
  pthread_mutex_t last_eaten_mutex;
  struct s_philo_data *data;
} t_philo;

typedef struct s_philo_data {
  unsigned int num_philo;
  unsigned int time_to_die;
  unsigned int time_to_eat;
  unsigned int time_to_sleep;
  pthread_mutex_t *forks;
  t_philo *philos;
  pthread_mutex_t printf_mutex;
  uint64_t start_time;
  bool sim_end;
  pthread_mutex_t sim_end_mutex;
} t_philo_data;

unsigned int ft_atoui(const char *num);
void exit_with_error(const char *message, int exit_code);

#endif
