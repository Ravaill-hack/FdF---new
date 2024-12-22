/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 14:17:33 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/*
Fonctions de debuggage :
		print_info_map(map);	
		print_info_list(*nodes);
*/

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc == 2)
	{
		var = init_var(argv[1]);
		ft_free_var(var);
		ft_putstr_fd("OK : it seems to work correctly", 1);
	}
	else
	{
		ft_putstr_fd("Error : wrong number of arguments", 2);
		return (0);
	}
}
