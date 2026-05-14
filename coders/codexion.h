/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   codexion.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 13:51:15 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/14 18:25:31 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define FIFO 1
# define EDF 2

typedef struct s_sim
{
	int	all_coders;
	int	tt_burnout;
	int	tt_compile;
	int	tt_debug;
	int	tt_refactor;
	int	req_compiles;
	int	dongle_cd;
	int	scheduler;
}	t_sim;

typedef struct s_coder
{
	int			id;
	pthread_t	thread_id;
}

int			ft_strcmp(const char *s1, const char *s2);
int			parse_input(char **av, t_sim *sim_data);
int			ft_strlen(char *str);
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *str);

#endif