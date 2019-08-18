/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:52:09 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/18 12:02:48 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_window(f_map *fmap)
{
	fmap->mlx = mlx_init();
	fmap->window = mlx_new_window(fmap->mlx, fmap->w_width, fmap->w_height, "FDF");
	mlx_key_hook(fmap->window, escclose, fmap);
	fmap->xgrid = creategrid(fmap);
	fmap->ygrid = creategrid(fmap);
	create_box(fmap);
	edit_box(fmap);
	centre_box(fmap);
	draw_grid(fmap);
	mlx_loop(fmap->mlx);
}
