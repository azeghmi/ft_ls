/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:02:45 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/01 15:20:21 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int						ft_time_compare(t_files *s1, t_files *s2)
{
	if (s1->infos.st_mtimespec.tv_sec >= s2->infos.st_mtimespec.tv_sec)
		return (-1);
	return (1);
}

int						ft_ascii_compare(t_files *s1, t_files *s2)
{
	return (ft_strcmp(s1->name, s2->name));
}
