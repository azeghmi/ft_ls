/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelstdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:49:09 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/12 12:51:53 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void					ft_filelstdel(t_files **head)
{
	t_files				*ptr;
	t_files				*node;

	if (head == NULL || *head == NULL)
		return ;
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
