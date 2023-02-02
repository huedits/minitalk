/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:16:17 by vimatheu          #+#    #+#             */
/*   Updated: 2023/02/01 21:24:00 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE "0123456789abcdef"

int	ft_printhex(unsigned long nbr, int flag)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_printhex((nbr / 16), flag);
		count += ft_printhex((nbr % 16), flag);
	}
	else
	{
		if (nbr < 10)
			return (ft_putchar(BASE[nbr]));
		else
			return (ft_putchar(BASE[nbr] - ('x' - flag)));
	}
	return (count);
}
