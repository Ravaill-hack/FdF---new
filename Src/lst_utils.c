/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:25:47 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 20:59:41 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_point	*ft_lst_last(t_point *nodes)
{
	while (nodes && nodes->next)
		nodes = nodes->next;
	return (nodes);
}

t_point	*ft_new_node(char *str, int i, int j)
{
	t_point	*node;

	node = (t_point *)calloc(1, sizeof(t_point));
	if (!node)
	{
		ft_putstr_fd("Error : node malloc failed", 2);
		return (NULL);
	}
	node->x = i;
	node->y = j;
	node->z = ft_atoi(str);
	node->x0 = node->x;
	node->y0 = node->y;
	node->z0 = node->z;
	node->col = ext_col(str);
	node->next = NULL;
	node->up = NULL;
	node->lft = NULL;
	return (node);
}

void	ft_lst_add_right(t_point **nodes, t_point *elem)
{
	if (!nodes)
	{
		ft_putstr_fd("Error : nodes** doesn't exist", 2);
		return ;
	}
	if (!(*nodes))
		*nodes = elem;
	else
		ft_lst_last(*nodes)->next = elem;
	elem->up = find_up(elem, *nodes);
	elem->lft = find_lft(elem, *nodes);
}

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
