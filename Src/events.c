/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:08:15 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/24 15:29:04 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	do_sth(int keyc, t_var *var)
{
	ft_printf("%d\n", keyc);
	if (keyc == 65307)
		ft_close_n_free(var);
	if (keyc == 113 || keyc == 119 || keyc == 97 || keyc == 115 || keyc == 122 || keyc == 120)
	{	
		ft_set_rot(var, keyc);
		ft_set_image(var);
		mlx_put_image_to_window(var->mlx_p, var->win_p, var->img->im_p, 0, 0);
	}
	return (0);
}

void	ft_close_aff(t_var *var)
{
	mlx_destroy_image(var->mlx_p, var->img->im_p);
	mlx_destroy_window(var->mlx_p, var->win_p);
	mlx_destroy_display(var->mlx_p);
}
