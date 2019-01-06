/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** think_rest.c
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "extern.h"
#include "philosopher.h"

extern pthread_mutex_t **chopstick_tab;

void think(t_philo *current_philo)
{
	int left_chop = current_philo->phil_value;
	int right_chop = ((current_philo->phil_value + 1) % current_philo->
			phil_total_nbr);

	current_philo->status = H_THINK;
	if (pthread_mutex_lock(chopstick_tab[left_chop]) == SUCCESS) {
		lphilo_take_chopstick(chopstick_tab[left_chop]);
		lphilo_think();
		sleep(TIME);
		pthread_mutex_unlock(chopstick_tab[left_chop]);
		lphilo_release_chopstick(chopstick_tab[left_chop]);
	} else if (pthread_mutex_lock(chopstick_tab[right_chop]) == SUCCESS) {
		lphilo_take_chopstick(chopstick_tab[right_chop]);
		lphilo_think();
		sleep(TIME);
		pthread_mutex_unlock(chopstick_tab[right_chop]);
		lphilo_release_chopstick(chopstick_tab[right_chop]);
	}
}

int take_decision(t_philo *current_philo, int count)
{
	int ret = 0;

	ret = rand();
	if (ret % 2 == 0)
		think(current_philo);
	else
		return (eat(current_philo, count));
	return (count);
}

void rest(t_philo *current_philo)
{
	current_philo->status = H_REST;
	lphilo_sleep();
	sleep(TIME);
}
