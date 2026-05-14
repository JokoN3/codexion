/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/14 16:50:59 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/14 17:34:36 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_num_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_int(char *str)
{
	long long	num;

	if (ft_strlen(str) > 12)
		return (0);
	num = ft_atoll(str);
	if (num > INT_MAX)
		return (0);
	return (1);
}

void	fill_data(t_sim *sim_data, char **av)
{
	sim_data->all_coders = ft_atoi(av[0]);
	sim_data->tt_burnout = ft_atoi(av[1]);
	sim_data->tt_compile = ft_atoi(av[2]);
	sim_data->tt_debug = ft_atoi(av[3]);
	sim_data->tt_refactor = ft_atoi(av[4]);
	sim_data->req_compiles = ft_atoi(av[5]);
	sim_data->dongle_cd = ft_atoi(av[6]);
}

int	parse_input(char **av, t_sim *sim_data)
{
	int	i;

	i = 0;
	while (i != 7)
	{
		if (is_num_str(av[i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i != 7)
	{
		if (is_int(av[i]) == 0)
			return (0);
		i++;
	}
	fill_data(sim_data, av);
	if (!ft_strcmp(av[7], "fifo"))
		sim_data->scheduler = FIFO;
	else if (!ft_strcmp(av[7], "edf"))
		sim_data->scheduler = EDF;
	else
		return (0);
	return (1);
}
