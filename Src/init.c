/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:01:04 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 15:55:55 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_var	*init_var(const char *path)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->map = init_map(path);
	var->mlx_p = mlx_init();
	var->win_p = mlx_new_window(var->mlx_p, X_WIN, Y_WIN, var->map->title);
	var->img = init_img(var->mlx_p);
	return (var);
}

t_img	*init_img(void *mlx_p)
{
	t_img	*im;

	im = (t_img *)malloc(sizeof(t_img));
	if (!im)
		return (NULL);
	im->im_p = mlx_new_image(mlx_p, X_WIN, Y_WIN);
	im->im = (int*)(mlx_get_data_addr(im->im_p, &im->bp, &im->sl, &im->ed));
	return (im);
}

t_map *init_map(const char *path)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->point = (t_point **)malloc(sizeof(t_point *));
	if(!map->point)
		return (NULL);
	get_map(map, path);
	return (map);
}

void	get_map(t_map *map, const char *path)
{
	int		j;
	int		fd;
	char	*line;

	j = -1;
	fd = open(path, O_RDONLY);
	line = NULL;
	while (line != NULL || j == -1)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
		j++;
		if (line == NULL)
			break ;
		if (j == 0)
			map->size_x = lst_create_n_add(map->point, line, j);
		else
			lst_create_n_add(map->point, line, j);
	}
	close (fd);
	map->size_y = j;
	map->title = get_title(path);
	map->path = ft_strdup(path);
}

int	lst_create_n_add(t_point **nodes, char *l, int j)
{
	char	**s_l;
	int		nb_val;
	int		i;

	nb_val = 0;
	i = 0;
	s_l = ft_split(l, ' ');
	if (!s_l)
	{
		ft_putstr_fd("Error : line split failed", 2);
		return (-1);
	}

	nb_val = ft_count_words(s_l) - 1;
	while (i < nb_val)
	{
		ft_lst_add_right(nodes, ft_new_node(s_l[i], i, j));
		i++;
	}
	ft_free_tab_c(s_l);
	return (nb_val);
}

t_point *ft_new_node(char *str, int i, int j)
{
	t_point	*node;

	node = (t_point *)malloc(sizeof(t_point));
	if (!node)
	{
		ft_putstr_fd("Error : node malloc failed", 2);		
		return (NULL);
	}
	node->x = i;
	node->y = j;
	node->z = ft_atoi(str);
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
