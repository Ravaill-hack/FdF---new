/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:25:47 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 15:48:43 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"


t_point	*ft_lst_last(t_point *nodes)
{
	while (nodes && nodes->next)
		nodes = nodes->next;
	return (nodes);
}
