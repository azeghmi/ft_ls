/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_default.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:46:00 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/12 15:49:52 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void				ft_simple_print(t_parsing *parsing)
{
	t_list				*node;
	t_files				*files;
	size_t				index;

	index = 0;
	node = parsing->list;
	while (node != NULL)
	{
		if (index > 0 && node->name != NULL)
			ft_putchar('\n');
		files = node->files;
		if (parsing->size > 1 && node->name != NULL && ++index)
		{
			write(1, node->name, ft_strlen(node->name) - 1);
			ft_printf(":\n");
		}
		while (files != NULL)
		{
			ft_putstr_endl(files->name, files->len);
			files = files->next;
		}
		node = node->next;
	}
}

static void				ft_fill_file_list(t_parsing *p, t_list *lst)
{
	char				*path;
	struct dirent		*file;
	struct stat			buffer;
	DIR					*directory;

	if ((directory = opendir(lst->name)) != NULL)
	{
		while ((file = readdir(directory)))
		{
			if (!(!(p->options & OPTION_A) && *file->d_name == '.'))
			{
				lstat((path = ft_strjoin(lst->name, file->d_name)), &buffer);
				ft_append(&lst->files, file->d_name, file->d_namlen, &buffer);
				free((void *)path);
			}
		}
		closedir(directory);
	}
	if (!(p->options & OPTION_F))
		ft_sort_list(lst, p);
}

int8_t					ft_recursive_lsdir(t_parsing *p)
{
	t_list				*tmp;

	tmp = p->list;
	while (tmp != NULL)
	{
		if (tmp->name != NULL)
		{
			ft_recur_lsdir_suite(p, tmp->name);
			if (tmp->next && tmp->next->name)
			{
				ft_putchar(10);
				write(1, tmp->next->name, ft_strlen(tmp->next->name) - 1);
				write(1, ":\n", 2);
			}
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

int8_t					ft_iterative_lsdir(t_parsing *ptr)
{
	t_list				*list;

	list = ptr->list;
	while (list != NULL)
	{
		if (list->name != NULL)
			ft_fill_file_list(ptr, list);
		list = list->next;
	}
	if (ptr->options & OPTION_R)
		ft_lstreverse_args(&ptr->list);
	ptr->options & OPTION_L ? ft_detailed_print(ptr) : ft_simple_print(ptr);
	return (EXIT_SUCCESS);
}
