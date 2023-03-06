/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:41:45 by vimatheu          #+#    #+#             */
/*   Updated: 2023/03/06 20:26:37 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) s)[i] = 0;
		i++;
	}
}

static int	check_limit(int res, int next, int sign)
{
	if (sign < 0)
	{
		if (-res < ((1 << 31) + next) / 10)
			return (0);
	}
	else
	{
		if (res > (~(1 << 31) - next) / 10)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *c)
{
	int				res;
	int				sig;

	res = 0;
	sig = 1;
	while (*c == ' ' || (*c >= 8 && *c <= 14))
		c++;
	if (*c == '+' || *c == '-')
	{
		if (*c == '-')
			sig *= -1;
		c++;
	}
	while (ft_isdigit(*c))
	{
		if (!check_limit(res, *c - '0', sig))
			return (0);
		res = res * 10 + (*c - '0');
		c++;
	}
	return (res * sig);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
