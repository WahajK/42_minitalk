/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:24:55 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/04 18:31:17 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstnew.c
 * @brief Creates a new list element.
 *
 * This function allocates memory for a new list element, initializes its
 * content with the provided value, and sets its next pointer to NULL.
 *
 * @param content The content to initialize the new list element with.
 * @return A pointer to the new list element, or NULL if memory allocation
 *         fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (0);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
