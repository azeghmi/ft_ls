/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file_informations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:23:05 by thflahau          #+#    #+#             */
/*   Updated: 2019/05/09 12:25:38 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				ft_print_type_and_permissions(mode_t perms)
{
	if ((perms & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if ((perms & S_IFMT) == S_IFREG)
		ft_putchar('-');
	else if ((perms & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((perms & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	else if ((perms & S_IFMT) == S_IFIFO)
		ft_putchar('p');
	else if ((perms & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((perms & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	ft_putchar(S_IRUSR & perms ? 'r' : '-');
	ft_putchar(S_IWUSR & perms ? 'w' : '-');
	ft_putchar(S_IXUSR & perms ? 'x' : '-');
	ft_putchar(S_IRGRP & perms ? 'r' : '-');
	ft_putchar(S_IWGRP & perms ? 'w' : '-');
	ft_putchar(S_IXGRP & perms ? 'x' : '-');
	ft_putchar(S_IROTH & perms ? 'r' : '-');
	ft_putchar(S_IWOTH & perms ? 'w' : '-');
	ft_putchar(S_IXOTH & perms ? 'x' : '-');
}

void				ft_print_date_of_last_modification(struct timespec *file)
{
	time_t			year;
	char			*time_of_last_modification;

	time_of_last_modification = ctime(&file->tv_sec);
	time_of_last_modification += 4;
	write(1, time_of_last_modification, 7);
	time_of_last_modification += 7;
	year = ft_atoi_light(time_of_last_modification + 9);
	if (year < 2019)
		ft_printf("%5i", year);
	else
		write(1, time_of_last_modification, 5);
	ft_putchar(' ');
}

static void			ft_print_all_informations(t_list *node, t_files *f)
{
	char			buffer[BUFF_SIZE];
	char			*fullpath;
	ssize_t			read;

	ft_print_type_and_permissions(f->infos.st_mode);
	ft_printf("%3u ", f->infos.st_nlink);
	ft_padding_uid(node, getpwuid(f->infos.st_uid)->pw_name);
	ft_padding_gid(node, getgrgid(f->infos.st_gid)->gr_name);
	if (S_ISCHR(f->infos.st_mode) || S_ISBLK(f->infos.st_mode))
		ft_printf("%3i,%4i ", major(f->infos.st_rdev), minor(f->infos.st_rdev));
	else
		ft_printf("%5u ", f->infos.st_size);
	ft_print_date_of_last_modification(&f->infos.st_mtimespec);
	write(1, f->name, f->len);
	if ((f->infos.st_mode & S_IFMT) == S_IFLNK)
	{
		write(1, " -> ", 4);
		fullpath = ft_strjoin(node->name, f->name);
		read = readlink(fullpath, buffer, BUFF_SIZE);
		read < 0 ? ft_printf("%s", strerror(errno)) : write(1, buffer, read);
		free((void *)fullpath);
	}
	ft_putchar('\n');
}

void				ft_detailed_print(t_parsing *parsing)
{
	t_list			*node;
	t_files			*files;
	size_t			index;

	index = 0;
	node = parsing->list;
	while (node != NULL)
	{
		files = node->files;
		if (index > 0 && node->name != NULL)
			ft_putchar('\n');
		if (parsing->size > 1 && node->name && ++index)
		{
			write(1, node->name, ft_strlen(node->name) - 1);
			write(1, ":\n", 2);
		}
		if (node->name != NULL)
			ft_print_total_blocks(files);
		while (files != NULL)
		{
			ft_print_all_informations(node, files);
			files = files->next;
		}
		node = node->next;
	}
}
