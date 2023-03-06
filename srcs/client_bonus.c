/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:41:48 by vimatheu          #+#    #+#             */
/*   Updated: 2023/03/06 20:26:15 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	g_wait;

int	main(int argc, char *argv[])
{
	pid_t	pid;
	size_t	i;

	i = 0;
	g_wait = 0;
	init_c();
	if (argc != 3)
		return (ft_printf("./client <server_id> <str>\n"));
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Error! Invalid PID!\n"));
	while (argv[2][i])
	{
		send_bit(pid, argv[2][i]);
		i++;
	}
	send_bit(pid, '\n');
	exit(0);
	while (1)
		pause();
	return (0);
}

void	init_c(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_flags = 0;
	sa.sa_handler = get_signal_c;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	get_signal_c(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("char sent!\n");
	else
		g_wait = 0;
}

void	send_bit(pid_t pid, char c)
{
	int			i;
	static int	error;

	error = 0;
	i = 0;
	while (i < 8 && error == 0)
	{
		if (!g_wait)
		{
			g_wait = 1;
			if (c & 1)
				error = kill(pid, SIGUSR1);
			else
				error = kill(pid, SIGUSR2);
			c >>= 1;
			i++;
			usleep(5000);
		}
	}
	if (error)
		exit(1);
}
