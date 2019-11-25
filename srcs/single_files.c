/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:55:50 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/05 11:54:21 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void					ft_sinfiles_ls(t_parsing *parsing, t_files *lst)
{
	while (lst != NULL)
	{
		if (parsing->options & OPTION_L)
		{
			ft_print_type_and_permissions(lst->infos.st_mode);
			ft_printf("%3u ", lst->infos.st_nlink);
			ft_padding_uid(NULL, getpwuid(lst->infos.st_uid)->pw_name);
			ft_padding_gid(NULL, getgrgid(lst->infos.st_gid)->gr_name);
			if (S_ISCHR(lst->infos.st_mode) || S_ISBLK(lst->infos.st_mode))
			{
				ft_printf("%3i,", major(lst->infos.st_rdev));
				ft_printf("%4i ", minor(lst->infos.st_rdev));
			}
			else
				ft_printf("%5u ", lst->infos.st_size);
			ft_print_date_of_last_modification(&lst->infos.st_mtimespec);
		}
		ft_putstr_endl(lst->name, lst->len);
		if ((lst->infos.st_mode & S_IFMT) == S_IFLNK)
			ft_read_links(lst->name);
		lst = lst->next;
	}
}
