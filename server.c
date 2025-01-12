/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:59:49 by muhakhan          #+#    #+#             */
/*   Updated: 2025/01/10 00:33:50 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

void	sig_handler(int signum)
{
	// static int	bit_count;
	// static char	ch;

	if (signum == SIGUSR1)
		ft_putstr_fd("Message received\n", 1);
	else if (signum == SIGUSR2)
		ft_putstr_fd("Message not received\n", 1);
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
