/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:01:04 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/24 14:42:31 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_var	*init_var(const char *path)
{
	t_var	*var;

	var = (t_var *)calloc(1, sizeof(t_var));
	if (!var)
		return (NULL);
	var->map = init_map(path);
	var->mlx_p = mlx_init();
	if (!var->mlx_p)
		return (free(var), NULL);
	var->win_p = mlx_new_window(var->mlx_p, X_WIN, Y_WIN, var->map->title);
	if (!var->win_p)
		return (free(var), NULL);
	var->img = init_img(var->mlx_p);
	if (!var->img)
		return (free(var), NULL);
	var->att = init_att();
	return (var);
}

t_map	*init_map(const char *path)
{
	t_map	*map;

	map = (t_map *)calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->point = (t_point **)calloc(1, sizeof(t_point *));
	if (!map->point)
		return (NULL);
	*(map->point) = NULL;
	get_map(map, path);
	return (map);
}

t_img	*init_img(void *mlx_p)
{
	t_img	*im;

	im = (t_img *)calloc(1, sizeof(t_img));
	if (!im)
		return (NULL);
	im->im_p = mlx_new_image(mlx_p, X_WIN, Y_WIN);
	im->bp = 0;
	im->sl = 0;
	im->ed = 0;
	im->im = mlx_get_data_addr(im->im_p, &im->bp, &im->sl, &im->ed);
	return (im);
}

t_att	init_att(void)
{
	t_att att;

	att.ang_x = 0;
	att.ang_y = 0;
	att.ang_z = 0;
	att.fac_z = 1;
	att.zoom = 1;
	att.x0 = 0;
	att.y0 = 0;
	return (att);
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
