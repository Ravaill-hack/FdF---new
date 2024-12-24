/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:25:24 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/24 11:50:28 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	init_image(t_var *var)
{
	double fact;
	double zoom;
	double angle;

	fact = 70;
	zoom = 100.0;
	angle = 30.0;
	draw_image(var, fact, zoom, angle);
}

void	draw_image(t_var *var, double fact, double zoom, double angle)
{
	t_point	*a;
	int		offset[2];

	a = *(var->map->point);
	offset[0] = X_WIN / 2;
	offset[1] = 0;
	ft_set_alt(var, fact);
	ft_set_zoom(var, zoom);
	ft_set_iso(var, angle);
	ft_set_offset(var, offset);
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
	char	*ptr;

	if (x < 0 || x > X_WIN || y < 0 || y > Y_WIN)
		return ;
	ptr = var->img->im + (y * var->img->sl) + x * (var->img->bp / 8);
	*(int *)ptr = col;
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

void	ft_set_offset(t_var *var, int offset[2])
{
	t_point *node;

	node = *(var->map->point);
	while (node != NULL)
	{
		node->x = (node->x + offset[0]);
		node->y = (node->y + offset[1]);
		node = get_next(node);
	}
}
