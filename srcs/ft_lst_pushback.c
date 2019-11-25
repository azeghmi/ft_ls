/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:31:22 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/03 16:48:53 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int8_t					ft_lst_pushback(t_list **lst, char const *data)
{
	t_list				*head;

	if (lst == NULL)
		return (-1);
	head = *lst;
	if (head == NULL)
	{
		if (!(*lst = ft_lstnew(data)))
			return (EXIT_FAILURE);
	}
	else
	{
		while (head->next != NULL)
			head = head->next;
		if (!(head->next = ft_lstnew(data)))
			return (-1);
	}
	return (EXIT_SUCCESS);
}
