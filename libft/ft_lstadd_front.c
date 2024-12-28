/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:25:55 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:05:35 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstadd_front.c
 * @brief Adds a new element at the beginning of the list.
 *
 * This function takes a pointer to the first element of a list and a new 
 * element to be added. It sets the new element's next pointer to the current 
 * first element and updates the list's head to the new element.
 *
 * @param lst A double pointer to the first element of the list.
 * @param new The new element to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
