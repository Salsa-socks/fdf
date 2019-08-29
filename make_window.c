/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:52:09 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/22 07:32:27 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int find_z(int x, int y, t_map *fmap)
{
	int z;
	int wd;

	z = 0;
	wd = 0;
	while (wd != y)
	{
		z = fmap->map[x][wd];
		wd++;
		if (wd == fmap->h + 1)
		{
			ft_putendl("Error: unable to find Z value");
			exit(0);
		}
	}
	return (z);
}

int		build_z(int key, t_map *fmap)
{
	if (key == 17)
	{
		fmap->height = 0;
		while (fmap->height != fmap->h)
		{
			fmap->width = 0;
			while (fmap->width != fmap->w)
			{
				if (fmap->map[fmap->height][fmap->width] != 0)
					fmap->map[fmap->height][fmap->width] += 10;
				fmap->xgrid[fmap->height][fmap->width] = 
					fmap->xgrid[fmap->height][fmap->width] - 
					fmap->map[fmap->height][fmap->width];
				fmap->width++;
			}
			fmap->height++;
		}
	}
	draw_grid(fmap);
	return (0);
}

void	make_window(t_map *fmap)
{
	fmap->mlx = mlx_init();
	fmap->window = mlx_new_window(fmap->mlx, fmap->w_width, fmap->w_height, "FDF");
	mlx_key_hook(fmap->window, escclose, fmap);
	mlx_key_hook(fmap->window, build_z, fmap);
	fmap->xgrid = creategrid(fmap);
	fmap->ygrid = creategrid(fmap);
	create_box(fmap);
	edit_box(fmap);
	centre_box(fmap);
	draw_grid(fmap);
	info_str(fmap);
	mlx_loop(fmap->mlx);
}
