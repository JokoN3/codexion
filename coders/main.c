/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 13:53:16 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/25 15:21:24 by yoneshev      ########   odam.nl         */
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

int	start_sim(t_sim *sim)
{
	
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