/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 15:59:57 by lmatkows         ###   ########.fr       */
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
		//print_info_map(var->map);
		ft_close_aff(var);
		ft_free_var(var);
	}
	else
	{
		ft_putstr_fd("Error : wrong number of arguments", 2);
		return (0);
	}
}
