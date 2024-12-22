/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:43:38 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 15:02:33 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	ext_col_low(char *str, int ind)
{
	char	*raw;
	int		nb;

	raw = ft_substr(str, (unsigned)ind, 6);
	nb = ft_atoi_base(raw, "0123456789abcdef");
	free (raw);
	raw = NULL;
	return (nb);
}

int	ext_col_up(char *str, int ind)
{
	char	*raw;
	int		nb;

	raw = ft_substr(str, (unsigned)ind, 6);
	nb = ft_atoi_base(raw, "0123456789ABCDEF");
	free (raw);
	raw = NULL;
	return (nb);
}

int	ext_col(char *str)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == ',')
			start = i + 3;
	}
	if (start == 0)
		return (0xFFFFFF);
	else
	{
		i = 0;
		while (i <= 5 && str[start + i] != '\0')
		{
			if (ft_strchr("0123456789abcdef", str[start + i]) != NULL)
				return (ext_col_low(str, start + i));
			else if (ft_strchr("0123456789ABCDEF", str[start + i]) != NULL)
				return (ext_col_up(str, start + i));
			i++;
		}
	}
	return (0xFFFFFF);
}
