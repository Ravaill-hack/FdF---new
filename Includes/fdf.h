/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:10:07 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/22 19:02:15 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define X_WIN 1400
# define Y_WIN 900

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "libft/Includes/libft.h"

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				col;
	struct s_point	*next;
	struct s_point	*up;
	struct s_point	*lft;
}	t_point;

typedef struct s_map
{
	char	*title;
	char	*path;
	t_point	**point;
	int		size_x;
	int		size_y;
}	t_map;

typedef struct s_img
{
	void	*im_p;
	int		bp;
	int		sl;
	int		ed;
	int		*im;
}	t_img;

typedef struct s_var
{
	void	*mlx_p;
	void	*win_p;
	t_map	*map;
	t_img	*img;
}	t_var;

/*
	Fonctions auxiliaires
*/
char	*get_title(const char *path);
t_point	*ft_lst_last(t_point *nodes);
int		ft_count_words(char **str);
/*
	Fonctions de debuggage
*/
void	print_info_list(t_point *nodes);
void	print_info_map(t_map *map);
/*
	Fonctions pour initialiser le projet
*/
t_var	*init_var(const char *path);
t_img	*init_img(void *mlx_p);
t_map 	*init_map(const char *path);
/*
	Fonctions pour parser la carte
*/
void	get_map(t_map *map, const char *path);
int		lst_create_n_add(t_point **nodes, char *l, int j);
t_point *ft_new_node(char *str, int i, int j);
void	ft_lst_add_right(t_point **nodes, t_point *elem);
t_point	*find_up(t_point *point, t_point *first);
t_point	*find_lft(t_point *point, t_point *first);
int		ext_col_up(char *str, int i);
int		ext_col_low(char *str, int i);
int		ext_col(char *str);
/*
	Fonctions pour creer l'image
*/
void	draw_image(t_var *var);
void	draw_point(t_var *var, int x, int y, int col);
/*
	Fonctions pour modifier l'affichage des noeuds
*/

/*
	Fonctions pour gerer les evenements
*/
int		do_sth(int keyc, t_var *var);
/*
	Fonctions pour dessiner des lignes
*/

/*
	Fonctions pour free et delete
*/
void	ft_free_tab_c(char **str);
int		ft_close_n_free(void *v);
void	ft_free_img(t_img *img);
void	ft_free_map(t_map *map);
void	ft_free_nodes(t_point **nodes);
void	ft_close_aff(t_var *var);

#endif