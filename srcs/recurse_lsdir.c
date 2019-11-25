/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_lsdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:57:10 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/12 14:59:16 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void			ft_display_files(t_files *files)
{
	size_t			index;

	index = 0;
	while (files != NULL)
	{
		ft_putstr_endl(files->name, files->len);
		files = files->next;
	}
}

static inline char	*ft_strcat(char *s1, char const *s2)
{
	char			*ptr;

	ptr = s1;
	s1 += ft_strlen(s1);
	while (*s2)
		*s1++ = *s2++;
	*s1 = 0;
	return (ptr);
}

static int8_t		ft_fill_lst(t_parsing *p, t_files **head, char const *name)
{
	uint16_t		i;
	char			path[512];
	struct dirent	*file;
	struct stat		buffer;
	DIR				*directory;

	i = 0;
	ft_fast_bzero(path, 512);
	if ((directory = opendir(name)) != NULL)
	{
		while ((file = readdir(directory)) != NULL)
			if (!(!(p->options & OPTION_A) && *file->d_name == '.'))
			{
				ft_strcpy(path, name);
				ft_strcat(path, "/");
				ft_strcat(path, file->d_name);
				stat(path, &buffer);
				ft_append(head, file->d_name, file->d_namlen, &buffer);
			}
		closedir(directory);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int8_t				ft_recur_lsdir_suite(t_parsing *p, char const name[512])
{
	t_files			*tmp;
	t_files			*files;

	files = NULL;
	if (ft_fill_lst(p, &files, name) == EXIT_FAILURE)
		ft_printf("ft_ls: %s: %s\n", name, strerror(errno));
	files = ft_recursive_merge_sort(files, &ft_ascii_compare);
	if (p->options & OPTION_T)
		files = ft_recursive_merge_sort(files, &ft_time_compare);
	if (p->options & OPTION_R)
		ft_lstreverse(&files);
	p->options & OPTION_L ? ft_detailed_files(files) : ft_display_files(files);
	tmp = files;
	ft_recur(tmp, name, p);
	ft_filelstdel(&files);
	return (EXIT_SUCCESS);
}

void				ft_recur(t_files *tmp, char const name[512], t_parsing *p)
{
	char			path[512];

	while (tmp != NULL)
	{
		if (S_ISDIR(tmp->infos.st_mode) && ft_strcmp(tmp->name, ".") \
		&& ft_strcmp(tmp->name, ".."))
		{
			ft_fast_bzero(path, 512);
			if (name[ft_strlen(name) - 1] == '/')
				ft_strncpy(path, name, ft_strlen(name) - 1);
			else
				ft_strcpy(path, name);
			ft_strcat(path, "/");
			ft_strcat(path, tmp->name);
			ft_printf("\n%s:\n", path);
			ft_recur_lsdir_suite(p, path);
		}
		tmp = tmp->next;
	}
}
