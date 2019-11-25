/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:52:12 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/05 12:04:25 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

size_t					ft_lstsize(t_list *lst)
{
	size_t				size;

	size = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		if (lst->name != NULL)
			++size;
		lst = lst->next;
	}
	return (size);
}
