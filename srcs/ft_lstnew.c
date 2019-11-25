/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:32:09 by thflahau          #+#    #+#             */
/*   Updated: 2019/03/28 22:13:39 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_list					*ft_lstnew(char const *content)
{
	t_list				*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(node->name = ft_strdup(content)))
		return (NULL);
	node->files = NULL;
	node->next = NULL;
	return (node);
}
