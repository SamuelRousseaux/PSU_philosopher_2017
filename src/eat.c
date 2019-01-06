/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** eat.c
*/

#include <unistd.h>
#include "extern.h"
#include "philosopher.h"

extern pthread_mutex_t **chopstick_tab;

void first_case_eat(t_philo *current_philo, int left_chop, int right_chop)
{
	if (chopstick_tab[left_chop] && chopstick_tab[right_chop]) {
		pthread_mutex_lock(chopstick_tab[left_chop]);
		lphilo_take_chopstick(chopstick_tab[left_chop]);
		pthread_mutex_lock(chopstick_tab[right_chop]);
		lphilo_take_chopstick(chopstick_tab[right_chop]);
		lphilo_eat();
		current_philo->status = H_EAT;
		pthread_mutex_unlock(chopstick_tab[left_chop]);
		lphilo_release_chopstick(chopstick_tab[left_chop]);
		pthread_mutex_unlock(chopstick_tab[right_chop]);
		lphilo_release_chopstick(chopstick_tab[right_chop]);
	}
	sleep(TIME);
}

void second_case_eat(t_philo *current_philo, int left_chop, int right_chop)
{
	pthread_mutex_lock(chopstick_tab[right_chop]);
	lphilo_take_chopstick(chopstick_tab[right_chop]);
	pthread_mutex_lock(chopstick_tab[left_chop]);
	lphilo_take_chopstick(chopstick_tab[left_chop]);
	lphilo_eat();
	current_philo->status = H_EAT;
	pthread_mutex_unlock(chopstick_tab[right_chop]);
	lphilo_release_chopstick(chopstick_tab[right_chop]);
	pthread_mutex_unlock(chopstick_tab[left_chop]);
	lphilo_release_chopstick(chopstick_tab[left_chop]);
	sleep(TIME);
}

int eat(t_philo *current_philo, int count)
{
	int left_chop = current_philo->phil_value;
	int right_chop = ((current_philo->phil_value + 1) % current_philo->
			phil_total_nbr);

	if (left_chop < right_chop) {
		first_case_eat(current_philo, left_chop, right_chop);
	} else {
		second_case_eat(current_philo, left_chop, right_chop);
	}
	return (count - 1);
}
