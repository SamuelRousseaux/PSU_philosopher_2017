/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** philosopher.h
*/

#ifndef PHILOSOPHER
# define PHILOSOPHER

#include <pthread.h>

typedef struct	s_data
{
	int nb_philo;
	int nb_eating;
} data_t;

typedef struct	s_philo
{
	unsigned long long int phil_value;
	unsigned long long int how_many_eat;
	unsigned long long int phil_total_nbr;
	pthread_t phil_thread;
	pthread_cond_t phil_cond;
	unsigned long long int status;
}t_philo;

# define H_EAT 1
# define H_THINK 2
# define H_REST 3
# define SUCCESS 0
# define FAIL 84
# define TIME 0.5
int init_table_of_phil(t_philo **table_philo, data_t *init);
void join_philo(t_philo **table_philo);
int eat(t_philo *current_philo, int count);
void rest(t_philo *current_philo);
int take_decision(t_philo *current_philo, int count);
void think(t_philo *current_philo);

#endif /*PHILOSOPHER*/
