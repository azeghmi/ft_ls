/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:45:46 by thflahau          #+#    #+#             */
/*   Updated: 2019/05/09 12:44:52 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int					main(int argc, char const **argv)
{
	t_parsing		parsing;

	ft_fast_bzero(&parsing, sizeof(t_parsing));
	if (ft_parse_args(argc, argv, &parsing) == EXIT_FAILURE)
		return (ft_print_usage(EXIT_FAILURE));
	ft_are_valid_directories(&parsing);
	if (parsing.sinfile != NULL)
	{
		ft_sinfiles_ls(&parsing, parsing.sinfile);
		if (ft_lstsize(parsing.list))
			ft_putchar('\n');
	}
	if (parsing.options & OPTION_CR)
		ft_recursive_lsdir(&parsing);
	else
		ft_iterative_lsdir(&parsing);
	ft_delete_garbage(&parsing);
	return (EXIT_SUCCESS);
}
