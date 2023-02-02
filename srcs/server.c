/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:41:50 by vimatheu          #+#    #+#             */
/*   Updated: 2023/02/01 21:05:03 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char    g_bit;

int main(void)
{
    ft_printf("Export PID: %i\n", getpid());
    init_s();
    while (1)
        pause();
    return (0);
}

void    init_s(void)
{
    struct sigaction    sa;
    
    ft_bzero(&sa, sizeof(sa));
    sa.sa_sigaction = get_signal_s;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

void    get_signal_s(int sig, siginfo_t *client, void *context)
{
    static char c;
    
    if (g_bit < 8)
    {
        if(sig == SIGUSR1)
            c += 1 << g_bit;
        else
            c += 0 << g_bit;
        g_bit++;
    }
    if (g_bit == 8)
    {
        write(1, &c, 1);
        g_bit = 0;
        if (c != '\n')
            kill(client->si_pid, SIGUSR1);
        c = 0;
    }
    kill(client->si_pid, SIGUSR2);
    (void)context;
}