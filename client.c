/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:59:43 by muhakhan          #+#    #+#             */
/*   Updated: 2025/01/09 23:12:08 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	int	pid;

	pid = ft_atoi(argv[1]);
	ft_printf("PID %d", pid);
	if (argc != 3)
		ft_printf("Usage: %s [server PID] [message]\n", argv[0]);
	else
	{
		kill(pid, SIGUSR1);
		kill(pid, SIGUSR2);
	}
}