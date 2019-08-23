/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_boxb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 07:48:16 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/23 13:02:14 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_draw_line(t_map *fmap)
{
	fmap->y = fmap->y1;
	fmap->x = fmap->x1;
	fmap->dx = abs(fmap->y2 - fmap->y1);
	fmap->dx = abs(fmap->x2 - fmap->x1);
	fmap->signx = fmap->x2 > fmap->x1 ? 1 : -1;
	fmap->signy = fmap->y2 > fmap->y1 ? 1 : -1;
	fmap->i = 0;
	fmap->tmp = 0;
}

void	draw_line(t_map *fmap)
{
	set_draw_line(fmap);
	if (fmap->dy > fmap->dx)
	{
		ft_swapint(&fmap->dx, &fmap->dy);
		fmap->tmp = 1;
	}
	fmap->d = 2 * fmap->dy - fmap->dx;
	while (fmap->i++ < fmap->dx)
	{
		mlx_pixel_put(fmap->mlx, fmap->window, fmap->x, fmap->y,fmap->color);
		while (fmap->d >= 0)
		{
			fmap->d = fmap->d - 2 * fmap->dx;
			if (fmap->tmp)
				fmap->x += fmap->signx;
			else
				fmap->y += fmap->signy;
		}
		fmap->d = fmap->d + 2 * fmap->dy;
		if (fmap->tmp)
			fmap->y += fmap->signy;
		else
			fmap->x += fmap->signx;

	}
}

void	draw_vert(t_map *fmap)
{
	fmap->height = 0;
	fmap->width = 0;
	while (fmap->height != fmap->h)
	{
		fmap->width = 0;
		while  (fmap->width != fmap->w)
		{
			fmap->x1 = fmap->xgrid[fmap->height][fmap->width];
			fmap->y1 = fmap->ygrid[fmap->height][fmap->width];
			if (fmap->height + 1 != fmap->h)
			{
				fmap->x2 = fmap->xgrid[fmap->height + 1][fmap->width];
				fmap->y2 = fmap->ygrid[fmap->height + 1][fmap->width];
			}
			draw_line(fmap);
			fmap->width++;
		}
		fmap->height++;
	}
}

void	draw_hori(t_map *fmap)
{
	fmap->height = 0;
	fmap->width = 0;
	while (fmap->height != fmap->h)
	{
		fmap->width = 0;
		while  (fmap->width != fmap->w)
		{
			fmap->x1 = fmap->xgrid[fmap->height][fmap->width];
			fmap->y1 = fmap->ygrid[fmap->height][fmap->width];
			if (fmap->width + 1 != fmap->w)
			{
				fmap->x2 = fmap->xgrid[fmap->height][fmap->width + 1];
				fmap->y2 = fmap->ygrid[fmap->height][fmap->width + 1];
			}
			draw_line(fmap);
			fmap->width++;
		}
		fmap->height++;
	}
}

void	draw_grid(t_map *fmap)
{
	draw_hori(fmap);
	draw_vert(fmap);
}
