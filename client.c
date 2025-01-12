/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:59:43 by muhakhan          #+#    #+#             */
/*   Updated: 2025/01/10 00:29:08 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

void	send_message(unsigned char c, int pid)
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
		usleep(500);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	unsigned char		*ptr;

	pid = ft_atoi(argv[1]);
	ft_printf("PID %d", pid);
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
