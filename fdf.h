/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:46:25 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/21 13:26:57 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "./minilix/mlx.h"

typedef struct	t_map
{
int				**map;
void			*mlx;
void			*window;
int				color;
int				w;
int				h;
int				w_width;
int				w_height;
int				**xgrid;
int				**ygrid;
int				dx;
int				dy;
int				d;
int				x1;
int				y1;
int				x2;
int				y2;
int				signx;
int				signy;
int				x;
int				y;
int				i;
int				tmp;
int				width;
int				height;
}				t_map;

void 			make_window(t_map * fmap);
int				**make_map(int fd, t_map *fmap);
int				**creategrid(t_map *fmlist);
int				strtointcopy(char *str);
int				**make_map(int fd, t_map *fmap);
void			line_h(int fd, t_map *fmap);
int				create_box(t_map *fmap);
int				find_space(t_map *fmap);
int				edit_box(t_map *fmap);
int				centre_box(t_map *fmap);
void			set_draw_line(t_map *fmap);
void			draw_line(t_map *fmap);
void			draw_vert(t_map *fmap);
void			draw_hori(t_map *fmap);
void			draw_grid(t_map *fmap);
int				**draw_map(int fd, t_map *fmap);
void			verify_file(int fd, char *file);
void			verify_width(int fd, int wd, inttwd);
void			verifyline(char *str);

#endif
