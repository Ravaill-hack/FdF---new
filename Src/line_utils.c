/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:25:53 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/24 10:55:37 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	draw_line(t_var *var, t_point *p1, t_point *p2)
{
	int		dx;
	int		dy;
	double	slope;

	if (p1->x == p2->x)
	{
		draw_vertical_line(var, p1, p2);
		return (0);
	}
	if (p1->y == p2->y)
	{
		draw_horizontal_line(var, p1, p2);
		return (0);
	}
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	slope = ((double)dy) / ((double)dx);
	if (slope < 1.0 && slope > -1.0)
		draw_other_line(var, p1, dx, dy);
	else
		draw_other_line_rev(var, p1, dx, dy);
	return (0);
}

void	draw_vertical_line(t_var *var, t_point *p1, t_point *p2)
{
	int	y0;

	y0 = p1->y;
	while (y0 != p2->y)
	{
		draw_point(var, p1->x, y0, p1->col);
		if (p1->y > p2->y)
			y0--;
		else
			y0++;
	}
	draw_point(var, p1->x, p1->y, p1->col);
}

void	draw_horizontal_line(t_var *var, t_point *p1, t_point *p2)
{
	int	x0;

	x0 = p1->x;
	while (x0 != p2->x)
	{
		draw_point(var, x0, p1->y, p1->col);
		if (p1->x > p2->x)
			x0--;
		else
			x0++;
	}
	draw_point(var, p1->x, p1->y, p1->col);
}

void	draw_other_line(t_var *var, t_point *p1, int dx, int dy)
{
	t_line	l;

	l.i = -1;
	l.p = 2 * abs(dy) - abs(dx);
	l.x0 = p1->x;
	l.y0 = p1->y;
	while (++l.i <= abs(dx))
	{
		draw_point(var, l.x0, l.y0, p1->col);
		if (dx > 0)
			l.x0 += 1;
		else
			l.x0 -= 1;
		if (l.p < 0)
			l.p = l.p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				l.y0 += 1;
			else
				l.y0 -= 1;
			l.p = l.p + 2 * abs(dy) - 2 * abs(dx);
		}
	}
}

void	draw_other_line_rev(t_var *var, t_point *p1, int dx, int dy)
{
	t_line	l;

	l.i = -1;
	l.p = 2 * abs(dy) - abs(dx);
	l.x0 = p1->x;
	l.y0 = p1->y;
	while (++l.i < abs(dy))
	{
		draw_point(var, l.x0, l.y0, p1->col);
		if (dy > 0)
			l.y0 += 1;
		else
			l.y0 -= 1;
		if (l.p < 0)
			l.p = l.p + 2 * abs(dx);
		else
		{
			if (dx > 0)
				l.x0 += 1;
			else
				l.x0 -= 1;
			l.p = l.p + 2 * abs(dx) - 2 * abs(dy);
		}
	}
}
