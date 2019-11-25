/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:31:45 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/12 15:38:05 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void				ft_padding(int a, int b)
{
	while (a++ < b + 2)
		ft_putchar(' ');
}

void					ft_padding_uid(t_list *head, char const *str)
{
	t_files				*ptr;
	uint8_t				len;
	static uint8_t		m;

	if (str == NULL)
		return ;
	len = ft_fast_strlen(str);
	if (head != NULL)
	{
		ptr = head->files;
		if (!m)
		{
			m = ft_fast_strlen(getpwuid(ptr->infos.st_uid)->pw_name);
			while (ptr != NULL)
			{
				if ((len = ft_strlen(getpwuid(ptr->infos.st_uid)->pw_name)) > m)
					m = len;
				ptr = ptr->next;
			}
		}
	}
	else
		m = len;
	write(1, str, len);
	ft_padding(len, m);
}

void					ft_padding_gid(t_list *head, char const *str)
{
	t_files				*ptr;
	uint8_t				len;
	static uint8_t		m;

	if (str == NULL)
		return ;
	len = ft_fast_strlen(str);
	if (head != NULL)
	{
		ptr = head->files;
		if (!m)
		{
			m = ft_fast_strlen(getgrgid(ptr->infos.st_gid)->gr_name);
			while (ptr != NULL)
			{
				if ((len = ft_strlen(getgrgid(ptr->infos.st_gid)->gr_name)) > m)
					m = len;
				ptr = ptr->next;
			}
		}
	}
	else
		m = len;
	write(1, str, len);
	ft_padding(len, m);
}
