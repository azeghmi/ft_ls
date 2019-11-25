/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_std_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:57:23 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/12 13:33:50 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void			ft_swap(t_files **a, t_files **b)
{
	*a = *b;
	*b = (*b)->next;
}

static void			ft_divide_list(t_files *lst, t_files **head, t_files **tail)
{
	while (lst != NULL && lst->next != NULL)
	{
		*tail = *head;
		*head = (*head)->next;
		lst = lst->next->next;
	}
	(*tail)->next = NULL;
}

static t_files		*ft_merge_lists(t_files **head, t_files **r, t_cmptr *cmp)
{
	t_files			*new_head;
	t_files			*tail;
	t_files			*next;

	next = NULL;
	new_head = NULL;
	while (*head != NULL || *r != NULL)
	{
		if (!(*r) || !(*head))
			ft_swap(&next, *r ? r : head);
		else
			ft_swap(&next, (*cmp)(*head, *r) < 0 ? head : r);
		if (new_head != NULL)
			tail->next = next;
		else
			new_head = next;
		tail = next;
	}
	return (new_head);
}

t_files				*ft_recursive_merge_sort(t_files *head, t_cmptr *cmp)
{
	t_files			*new_head;
	t_files			*right;
	t_files			*last;

	if (head == NULL || head->next == NULL)
		return (head);
	last = head;
	right = head;
	new_head = NULL;
	ft_divide_list(head, &right, &last);
	head = ft_recursive_merge_sort(head, cmp);
	right = ft_recursive_merge_sort(right, cmp);
	return (ft_merge_lists(&head, &right, cmp));
}

void				ft_sort_list(t_list *lst, t_parsing *parsing)
{
	lst->files = ft_recursive_merge_sort(lst->files, &ft_ascii_compare);
	if (parsing->options & OPTION_T)
		lst->files = ft_recursive_merge_sort(lst->files, &ft_time_compare);
	if (parsing->options & OPTION_R)
		ft_lstreverse(&lst->files);
}
