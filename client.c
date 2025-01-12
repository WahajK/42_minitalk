/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:59:43 by muhakhan          #+#    #+#             */
/*   Updated: 2025/01/12 21:12:54 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"


static void	send_message(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Invalid PID\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Invalid PID\n");
				exit(1);
			}
		}
		usleep(100);
		i--;
	}
}

static void	handle_ack(int signum)
{
	(void)signum;
	ft_printf("Message received by server!\n");
}

int	main(int argc, char *argv[])
{
	int					pid;
	unsigned char		*ptr;
	struct sigaction	sa;

	pid = ft_atoi(argv[1]);
	sa.sa_flags = 0;
	sa.sa_handler = handle_ack;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Sigaction Error\n");
		return (1);
	}
	if (argc != 3)
		ft_printf("Usage: %s [server PID] [message]\n", argv[0]);
	else
	{
		ptr = (unsigned char *) argv[2];
		while (*ptr)
			send_message(*(ptr++), pid);
		send_message('\0', pid);
	}
}
