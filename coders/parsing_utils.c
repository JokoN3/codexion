/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/14 16:58:34 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/14 17:26:22 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

int	ft_atoi(const char *nptr)
{
	long		res;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	res = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		&& nptr[i] != '\0')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i] != '\0')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
