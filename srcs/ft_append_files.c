/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:46:45 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/05 12:10:14 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static t_files	*ft_filelstnew(char const *s, int64_t size, t_stat *buffer)
{
	t_files		*node;

	if (!(node = (t_files *)malloc(sizeof(t_files))))
		return (NULL);
	if (!(node->name = ft_strndup(s, size)))
		return (NULL);
	if (buffer != NULL)
		node->infos = *buffer;
	node->len = size;
	node->next = NULL;
	return (node);
}

int8_t			ft_append(t_files **lst, char const *s, int64_t n, t_stat *buf)
{
	t_files		*head;

	if (lst == NULL)
		return (EXIT_FAILURE);
	else if (*lst == NULL)
	{
		if (!(*lst = ft_filelstnew(s, n, buf)))
			return (EXIT_FAILURE);
	}
	else
	{
		head = *lst;
		while (head->next != NULL)
			head = head->next;
		if (!(head->next = ft_filelstnew(s, n, buf)))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
