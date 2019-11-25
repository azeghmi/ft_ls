/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:46:19 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/12 14:50:30 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				ft_add_slash_to_path(t_list *list)
{
	char			*ptr;

	while (list != NULL)
	{
		if (list->name != NULL)
		{
			ptr = list->name;
			list->name = ft_strjoin(list->name, "/");
			free((void *)ptr);
		}
		list = list->next;
	}
}

void				ft_get_single_files_details(t_parsing *ptr, char const *str)
{
	t_stat			buffer;

	lstat(str, &buffer);
	ft_append(&ptr->sinfile, str, ft_fast_strlen(str), &buffer);
}

void				ft_are_valid_directories(t_parsing *parsing)
{
	DIR				*dir;
	t_list			*ptr;

	ptr = parsing->list;
	while (ptr != NULL)
	{
		if ((dir = opendir(ptr->name)) != NULL)
			closedir(dir);
		else
		{
			if (errno != ENOTDIR)
			{
				write(1, "ft_ls: ", 7);
				perror(ptr->name);
			}
			else if (ptr->name[ft_strlen(ptr->name) - 1] == '/')
				ft_printf("ft_ls: %s: Not a directory\n", ptr->name);
			else
				ft_get_single_files_details(parsing, ptr->name);
			ft_strdel(&ptr->name);
		}
		ptr = ptr->next;
	}
	ft_add_slash_to_path(parsing->list);
}

static int8_t		ft_parse_options(char const *options, t_parsing **ptr)
{
	while (*(++options))
	{
		if (*options == 'l')
			(*ptr)->options |= OPTION_L;
		else if (*options == 'a')
			(*ptr)->options |= OPTION_A;
		else if (*options == 't')
			(*ptr)->options |= OPTION_T;
		else if (*options == 'r')
			(*ptr)->options |= OPTION_R;
		else if (*options == 'R')
			(*ptr)->options |= OPTION_CR;
		else if (*options == 'f')
		{
			(*ptr)->options |= OPTION_F;
			(*ptr)->options |= OPTION_A;
		}
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", *options);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int8_t				ft_parse_args(int argc, char const **argv, t_parsing *ptr)
{
	char			*path;
	uint16_t		index;

	index = 0;
	while (index++ < argc - 1)
	{
		if (*argv[index] == '-')
		{
			if (ft_parse_options(argv[index], &ptr) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (++ptr->size)
			if (ft_lst_pushback(&ptr->list, argv[index]) < 0)
				return (EXIT_FAILURE);
	}
	if (!ptr->size)
	{
		path = ft_strdup(".");
		if (ft_lst_pushback(&ptr->list, path) < 0)
			return (EXIT_FAILURE);
		free((void *)path);
	}
	return (EXIT_SUCCESS);
}
