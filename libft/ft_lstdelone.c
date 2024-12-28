/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:29:21 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:06:01 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstdelone.c
 * @brief Deletes a single element of a linked list.
 *
 * This function takes a pointer to a linked list element and a function
 * pointer to a delete function. It applies the delete function to the
 * content of the element and then frees the element itself.
 *
 * @param lst The element of the list to delete.
 * @param del The function to delete the content of the element.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
