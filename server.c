/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:59:49 by muhakhan          #+#    #+#             */
/*   Updated: 2025/01/12 22:06:23 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"
#include "minitalk.h"

t_msg	g_message = {0, 0};

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		g_message.c |= (1 << (7 - g_message.bits));
	g_message.bits++;
	if (g_message.bits == 8)
	{
		if (g_message.c == '\0')
		{
			ft_printf("%c", '\n');
			kill(info->si_pid, SIGUSR2);
		}
		else
			ft_printf("%c", g_message.c);
		g_message.bits = 0;
		g_message.c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Sigaction Error");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
