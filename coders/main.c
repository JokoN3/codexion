/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 13:53:16 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/25 17:34:05 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_sim_data(t_sim sim)
{
	printf("Number of coders: %d\n", sim.all_coders);
	printf("TT_Burnout: %d\n", sim.tt_burnout);
	printf("TT_Compile: %d\n", sim.tt_compile);
	printf("TT_Debug: %d\n", sim.tt_debug);
	printf("TT_Refactor: %d\n", sim.tt_refactor);
	printf("Required compiles: %d\n", sim.req_compiles);
	printf("Dongle cooldown: %d\n", sim.dongle_cd);
	if (sim.scheduler == FIFO)
		printf("Scheduler: FIFO\n");
	else if (sim.scheduler == EDF)
		printf("Scheduler: EDF\n");
	printf("Start time: %lld\n", sim.start_time);
}

void	assign_dongles(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->all_coders)
	{
		if (i == sim->all_coders - 1)
		{
			sim->coders[i].left = &sim->dongles[0];
			sim->coders[i].right = &sim->dongles[i];
		}
		else
		{
			sim->coders[i].left = &sim->dongles[i];
			sim->coders[i].right = &sim->dongles[i + 1];
		}
		i++;
	}
}


int	init_sim(t_sim *sim)
{
	int	i;

	i = 0;
	sim->coders = malloc(sizeof(t_coder) * sim->all_coders);
	if (!sim->coders)
		return (-1);
	sim->dongles = malloc(sizeof(t_dongle) * sim->all_coders);
	if (!sim->dongles)
		return (free(sim->coders), -1);
	pthread_mutex_init(&sim->data_lock, NULL);
	pthread_mutex_init(&sim->print_lock, NULL);
	while (i < sim->all_coders)
	{
		pthread_mutex_init(&sim->dongles[i].mutex, NULL);
		sim->dongles[i].last_used = 0;
		sim->coders[i].id = i + 1;
		sim->coders[i].sim = sim;
		sim->coders[i].compiles = 0;
		pthread_mutex_init(&sim->coders[i].coder_lock, NULL);
		i++;
	}
	assign_dongles(sim);
	return (0);
}

int main(int ac, char **av)
{
	t_sim	sim_data;

	if (ac != 9)
		return (printf("bad arg count"), 1);
	av++;
	if (parse_input(av, &sim_data) == 0)
		return (printf("no\n"), 1);
	av--;
	sim_data.start_time = get_time_ms();
	print_sim_data(sim_data);
	
	return (0);
}