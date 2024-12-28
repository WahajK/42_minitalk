/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:21:01 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:01:14 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

/**
 * ft_atoi - Converts a string to an integer.
 * @str: The string to be converted.
 *
 * This function takes a string as input and converts it to an integer.
 * It skips any leading whitespace characters (spaces, tabs, newlines,
 * vertical tabs, form feeds, and carriage returns). If the first
 * non-whitespace character is a '-' sign, the resulting integer will be
 * negative. If the first non-whitespace character is a '+' sign, it is
 * ignored. The function then processes the subsequent numeric characters
 * and constructs the integer value. The conversion stops when a non-numeric
 * character is encountered.
 *
 * Return: The converted integer value.
 */
int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' '
		|| *str == '\t'
		|| *str == '\n'
		|| *str == '\v'
		|| *str == '\f'
		|| *str == '\r')
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
