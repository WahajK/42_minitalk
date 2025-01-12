/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:59:43 by muhakhan          #+#    #+#             */
/*   Updated: 2025/01/12 22:05:45 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

int	g_bit_control = 1;

static void	send_message(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_bit_control = 0;
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
		while (g_bit_control != 1)
			usleep(10);
		i--;
	}
}

static void	handle_ack(int signum)
{
	(void)signum;
	if (signum == SIGUSR1)
		g_bit_control = 1;
	else if (signum == SIGUSR2)
	{
		ft_printf("Message received by server!\n");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	unsigned char		*ptr;

	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, &handle_ack);
	signal(SIGUSR2, &handle_ack);
	if (argc != 3)
		ft_printf("Usage: %s [server PID] [message]\n", argv[0]);
	else
	{
		ptr = (unsigned char *) argv[2];
		while (*ptr)
			send_message(*(ptr++), pid);
		send_message('\0', pid);
	}
	while (1)
		pause();
}
