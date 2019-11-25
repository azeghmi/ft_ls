/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:01:24 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/03 16:04:32 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void						ft_read_links(char const *path)
{
	ssize_t					bytes;
	char					buffer[BUFF_SIZE];

	write(1, " -> ", 4);
	if ((bytes = readlink(path, buffer, BUFF_SIZE)) < 0)
		ft_printf("%s", strerror(errno));
	else
		write(1, buffer, bytes);
	ft_putchar('\n');
}
