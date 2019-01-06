/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** join_thread.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"
#include "philosopher.h"

void join_philo(t_philo **table_philo)
{
	for (int count = 0; table_philo[count] != NULL; count++)
	{
		pthread_join(table_philo[count]->phil_thread, NULL);
	}
}
