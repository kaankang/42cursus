/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanig <kkanig@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:08:56 by kkanig            #+#    #+#             */
/*   Updated: 2023/04/19 12:42:31 by kkanig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "sys/time.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct philo
{
	int				philo_id;
	int				eat_number;
	unsigned long	last_eat;
	pthread_t		philo;
}					t_philo;

typedef struct s_list
{
	int				philo_number;
	int				eat_time;
	int				dead_time;
	int				sleep_time;
	int				philo_max_eat;
	int				start_time;
	int				philo_index;
	int				dead;
	pthread_mutex_t	mutex;
	pthread_t		*thread;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}					t_list;

void				arg_control(int ac, char **av, t_list *data);
void				thread_creat(t_list *data);
void				creat_data(t_list *data);
void				*one_philo(void *data);
void				waiting_time(int time);
void				dead_control(t_list *data);
void				mutex_destroy(t_list *data);
void				mutex_creat(t_list *data);
int					dead(t_list *data, int index);
int					ft_atoi(char *str);
int					eating(t_list *data, int index);
int					error_control(t_list *data);
int					control(t_list *data);
int					thinking(t_list *data, int index);
int					sleeping(t_list *data, int index);
int					eat_philo(t_list *data);
int					is_dead(t_list *data, int index, char *str);
unsigned long		get_time(void);
unsigned long		get_passed_time(unsigned long begin);

#endif