/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:25:24 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 22:16:15 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	init_image(t_var *var)
{
	double fact;
	double zoom;
	double angle;

	fact = 0.5;
	zoom = 5.0;
	angle = 30.0;
	draw_image(var, fact, zoom, angle);
}

void	draw_image(t_var *var, double fact, double zoom, double angle)
{
	t_point	*a;

	a = *(var->map->point);
	ft_set_alt(var, fact);
	ft_set_zoom(var, zoom);
	ft_set_iso(var, angle);
	while (a)
	{
		if (a->up != NULL)
			draw_line(var, a, a->up);
		if (a->lft != NULL)
			draw_line(var, a, a->lft);
		a = a->next;
	}
}

void	draw_point(t_var *var, int x, int y, int col)
{
	int	*ptr;

	ptr = var->img->im + (y * var->img->sl) + x * (var->img->bp / 8);
	*ptr = col;
}

void	ft_set_alt(t_var *var, double fact)
{
	t_point *node;

	node = *(var->map->point);
	while (node != NULL)
	{
		node->z = (int)(fact * node->z0);
		node = get_next(node);
	}
}

void	ft_set_zoom(t_var *var, double zoom)
{
	t_point *node;

	node = *(var->map->point);
	while (node != NULL)
	{
		node->x = (int)((node->x0 - node->y) * zoom);
		node->y = (int)((node->x0 + node->y) * zoom);
		node = get_next(node);
	}
}

void	ft_set_iso(t_var *var, double angle)
{
	t_point *node;
	double	rad;

	node = *(var->map->point);
	rad = angle * PI / 180;
	while (node != NULL)
	{
		node->x = (int)((node->x) * cos(rad));
		node->y = (int)((node->y) * sin(rad)) - node->z;
		node = get_next(node);
	}
}
