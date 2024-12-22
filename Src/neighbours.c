/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:26:13 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 13:59:06 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_point	*find_up(t_point *point, t_point *first)
{
	if (point->y == 0)
		return (NULL);
	while (first)
	{
		if ((first->y == point->y - 1) && (first->x == point->x))
			return (first);
		first = first->next;
	}
	return (NULL);
}

t_point	*find_lft(t_point *point, t_point *first)
{
	if (point->x == 0)
		return (NULL);
	while (first)
	{
		if ((first->y == point->y) && (first->x == point->x - 1))
			return (first);
		first = first->next;
	}
	return (NULL);
}
