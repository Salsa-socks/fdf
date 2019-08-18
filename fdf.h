/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:46:25 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/18 14:08:52 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "./minilix/mlx.h"

typedef struct	f_map
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
int				sign1;
int				sign2;
int				x;
int				y;
int				i;
int				swapit;
int				width;
int				height;
}				f_map;

void 			make_window(f_map * fmap);
int				**creategrid(f_map *fmlist);


#endif
