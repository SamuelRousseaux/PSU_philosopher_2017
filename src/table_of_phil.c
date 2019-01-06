/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** table_of_phil.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include "extern.h"
#include "philosopher.h"

pthread_mutex_t **chopstick_tab;

void *philosophe_does(void *data)
{
	t_philo *current_philo = (t_philo *)data;
	int count = current_philo->how_many_eat;
	while (count != 0){
		if (current_philo->status == H_REST)
			count = take_decision(current_philo, count);
		else if (current_philo->status == H_THINK)
			count = eat(current_philo, count);
		else if (current_philo->status == H_EAT)
			rest(current_philo);
	}
	return (NULL);
}

int init_table_malloc_part(t_philo **table_philo, int count)
{
	table_philo[count] = malloc(sizeof(t_philo));
	chopstick_tab[count] = malloc(sizeof(pthread_mutex_t) * 100);
	if (table_philo[count] == NULL || chopstick_tab[count] == NULL)
		return (FAIL);
	return (SUCCESS);
}

int init_table_of_phil(t_philo **table_philo, data_t *init)
{
	table_philo = malloc(sizeof(t_philo *) * (init->nb_philo + 1));
	chopstick_tab = malloc(sizeof(pthread_mutex_t *) *
				(init->nb_philo + 1));
	if (table_philo == NULL || chopstick_tab == NULL)
		return (FAIL);
	table_philo[init->nb_philo] = NULL;
	chopstick_tab[init->nb_philo] = NULL;
	for (int count = 0; count < init->nb_philo; count++) {
		if (init_table_malloc_part(table_philo, count) == FAIL)
			return (FAIL);
		table_philo[count]->phil_value = count;
		table_philo[count]->how_many_eat = init->nb_eating;
		table_philo[count]->phil_total_nbr = init->nb_philo;
		table_philo[count]->status = H_REST;
		pthread_mutex_init(chopstick_tab[count], NULL);
		pthread_create(&(table_philo[count]->phil_thread), NULL,
				&philosophe_does, (void *)table_philo[count]);
	}
	join_philo(table_philo);
	return (SUCCESS);
}
