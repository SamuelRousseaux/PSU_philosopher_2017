/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"
#include "philosopher.h"

int help(void)
{
	printf("USAGE\n\t./philo -p nbr_p -e nbr_e\n\n");
	printf("DESCRIPTION\n");
	printf("\t-p nbr_p number of philosophers\n");
	printf("\t-e nbr_e maximum number times a philosopher");
	printf("eats before exiting the program\n");
	return (SUCCESS);
}

data_t *check_args(data_t *data, int n)
{
	if (n != 2)
		return (NULL);
	else if (data->nb_philo <= 1 || data->nb_eating <= 0)
		return (NULL);
	return (data);
}

int isnum(char *str)
{
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

data_t *handle_args(int argc, char **argv, data_t *data)
{
	int n = 0;

	data = malloc(sizeof(data_t));
	if (strcmp(argv[1], "--help") == 0)
		help();
	else if (argc == 5 && data != NULL) {
		for (int i = 1 ; i <= 3 ; i += 2) {
			if (strcmp(argv[i], "-p") == 0 && isnum(argv[i + 1])) {
				data->nb_philo = atoi(argv[i + 1]);
				n++;
			} else if (strcmp(argv[i], "-e") == 0 &&
					isnum(argv[i + 1])) {
				data->nb_eating = atoi(argv[i + 1]);
				n++;
			}
		}
	} else
		return (NULL);
	return (check_args(data, n));
}

int main(int argc, char **argv)
{
	data_t *data = NULL;
	t_philo *table_philo = NULL;

	srand(time(NULL));
	if (argc < 2)
		return (help());
	data = handle_args(argc, argv, data);
	if (data == NULL)
		return (FAIL);
	RCFStartup(argc, argv);
	init_table_of_phil(&table_philo, data);
	RCFCleanup();
	return (SUCCESS);
}
