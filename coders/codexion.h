/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   codexion.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 13:51:15 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/25 15:27:48 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>

# define FIFO 1
# define EDF 2

typedef struct s_sim
{
	int				all_coders;
	int				tt_burnout;
	int				tt_compile;
	int				tt_debug;
	int				tt_refactor;
	int				req_compiles;
	int				dongle_cd;
	int				scheduler;
	long long		start_time;
	struct s_coder *coders;
	struct s_dongle	*dongles;
}	t_sim;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	long long		last_used;
}	t_dongle;

typedef struct s_coder
{
	int				id;
	pthread_t		thread_id;
	int				compiles;
	long long		last_compile;
	t_dongle		left;
	t_dongle		right;
	pthread_mutex_t	coder_lock;
	t_sim			*sim;
}	t_coder;

int			ft_strcmp(const char *s1, const char *s2);
int			parse_input(char **av, t_sim *sim_data);
int			ft_strlen(char *str);
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *str);
long long	get_time_ms(void);

#endif