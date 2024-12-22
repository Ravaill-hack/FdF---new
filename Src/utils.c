/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:26:20 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 15:10:28 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	ft_count_words(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

char	*get_title(const char *path)
{
	char	*title;
	char	**temp;
	int		i;

	i = 0;
	title = NULL;
	temp = ft_split(path, '/');
	if (!temp)
		return (NULL);
	while (temp[i] != NULL)
		i++;
	if (i > 0)
		title = ft_strdup(temp[i - 1]);
	ft_free_tab_c(temp);
	return (title);
}
