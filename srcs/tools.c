/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:48:01 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/03 14:26:29 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int8_t				ft_print_usage(int8_t error)
{
	write(1, "usage: ls [-Raflrt] [file ...]\n", 31);
	return (error);
}

void				ft_delete_garbage(t_parsing *node)
{
	t_list			*ptr;

	if (node != NULL)
	{
		ft_filelstdel(&node->sinfile);
		ptr = node->list;
		while (ptr != NULL)
		{
			ft_filelstdel(&ptr->files);
			ptr = ptr->next;
		}
		ft_lstdel(&node->list);
	}
}
