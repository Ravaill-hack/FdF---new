/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:08:15 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 19:17:00 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	do_sth(int keyc, t_var *var)
{
	if (keyc == 65307)
		ft_close_n_free(var);
	return (0);
}

void	ft_close_aff(t_var *var)
{
	mlx_destroy_image(var->mlx_p, var->img->im_p);
	mlx_destroy_window(var->mlx_p, var->win_p);
	mlx_destroy_display(var->mlx_p);
}
