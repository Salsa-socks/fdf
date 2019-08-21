/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:46:25 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/21 08:37:07 by bnkosi           ###   ########.fr       */
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
int				**creategrid(t_map *fmlist);


#endif
