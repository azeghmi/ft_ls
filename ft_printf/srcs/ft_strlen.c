/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:25:46 by thflahau          #+#    #+#             */
/*   Updated: 2019/02/01 14:25:46 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

size_t					ft_strlen(char const *str)
{
	size_t				length;

	if (!str || !(*str))
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}
