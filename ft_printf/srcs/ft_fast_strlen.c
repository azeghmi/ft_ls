/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:23:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/03/28 22:57:00 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static int				ft_zero_in_word(char const *ptr, char const *str)
{
	t_ulli				i;
	size_t				size;

	i = 0;
	size = sizeof(unsigned long int);
	while (ptr[i] && i <= size)
		i++;
	return (i < size ? (ptr - str + i) : -1);
}

size_t					ft_fast_strlen(char const *str)
{
	char				*ptr;
	unsigned long int	*addr;
	unsigned long int	step;

	if (str == NULL)
		return (0);
	ptr = (char *)str;
	while (((unsigned long int)ptr & (sizeof(unsigned long int) - 1)) != 0)
		if (!(*ptr++))
			return (ptr - str - 1);
	addr = (unsigned long int *)ptr;
	while (1)
	{
		step = *addr++;
		if (((step - 0x101010101010101) & ~step & 0x8080808080808080))
			if (ft_zero_in_word((char *)(addr - 1), str) != -1)
				return ((size_t)ft_zero_in_word((char *)(addr - 1), str));
	}
	return (0);
}
