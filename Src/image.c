/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:25:24 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 19:08:36 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	draw_image(t_var *var)
{
	int	x;
	int	y;
	int	col;

	x = 3;
	y = 3;
	col = 0XFF00FF;
	draw_point(var, x, y, col);
}

void	draw_point(t_var *var, int x, int y, int col)
{
	int	*ptr;

	ptr = var->img->im + (y * var->img->sl) + x * (var->img->bp / 8);
	*ptr = col;
}
