/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:05:36 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/01 14:06:21 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void					ft_print_total_blocks(t_files *head)
{
	uint16_t			blocks;

	blocks = 0;
	while (head != NULL)
	{
		blocks += head->infos.st_blocks;
		head = head->next;
	}
	ft_printf("total %u\n", blocks);
}
