/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_default2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 23:19:30 by azeghmi           #+#    #+#             */
/*   Updated: 2019/04/25 23:19:33 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void				ft_print_infs(t_files *files)
{
	struct passwd		*tmp;
	struct group		*ptr;

	ft_print_type_and_permissions(files->infos.st_mode);
	ft_printf("%3u ", files->infos.st_nlink);
	if ((tmp = getpwuid(files->infos.st_uid)) != NULL)
		ft_padding_uid(NULL, tmp->pw_name);
	if ((ptr = getgrgid(files->infos.st_gid)) != NULL)
		ft_padding_gid(NULL, ptr->gr_name);
	if (S_ISCHR(files->infos.st_mode) || S_ISBLK(files->infos.st_mode))
	{
		ft_printf("%3i,", major(files->infos.st_rdev));
		ft_printf("%4i ", minor(files->infos.st_rdev));
	}
	else
		ft_printf("%5u ", files->infos.st_size);
	ft_print_date_of_last_modification(&files->infos.st_mtimespec);
	write(1, files->name, files->len);
	ft_putchar(10);
}

void					ft_detailed_files(t_files *files)
{
	if (files != NULL)
		ft_print_total_blocks(files);
	while (files != NULL)
	{
		ft_print_infs(files);
		files = files->next;
	}
}
