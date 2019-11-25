/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:29:12 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/02 19:23:55 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				ft_lstdel(t_list **head)
{
	t_list			*ptr;
	t_list			*node;

	node = *head;
	while (node != NULL)
	{
		ptr = node->next;
		ft_strdel(&node->name);
		free((void *)node);
		node = ptr;
	}
	*head = NULL;
}
