/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:41:53 by vimatheu          #+#    #+#             */
/*   Updated: 2023/03/06 20:20:34 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include "../ft_printf/includes/ft_printf.h"

/******************************************************************************/
/*                               client                                       */
/******************************************************************************/
void	init_c(void);
void	get_signal_c(int sig);
void	send_bit(pid_t pid, char c);

/******************************************************************************/
/*                               server                                       */
/******************************************************************************/
void	init_s(void);
void	get_signal_s(int sig, siginfo_t *client, void *context);

/******************************************************************************/
/*                                utils                                       */
/******************************************************************************/
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *c);
int		ft_isdigit(int c);

#endif
