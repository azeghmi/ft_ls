/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:53:05 by thflahau          #+#    #+#             */
/*   Updated: 2019/03/30 13:48:52 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void					ft_lstreverse_args(t_list **head)
{
	t_list				*ptr;
	t_list				*prev_node;
	t_list				*next_node;

	ptr = *head;
	prev_node = NULL;
	if (head && *head && (*head)->next)
	{
		while (ptr != NULL)
		{
			next_node = ptr->next;
			ptr->next = prev_node;
			prev_node = ptr;
			ptr = next_node;
		}
		*head = prev_node;
	}
}

void					ft_lstreverse(t_files **head)
{
	t_files				*ptr;
	t_files				*prev_node;
	t_files				*next_node;

	ptr = *head;
	prev_node = NULL;
	if (head && *head && (*head)->next)
	{
		while (ptr != NULL)
		{
			next_node = ptr->next;
			ptr->next = prev_node;
			prev_node = ptr;
			ptr = next_node;
		}
		*head = prev_node;
	}
}
