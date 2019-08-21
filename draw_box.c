/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 06:17:30 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/21 07:12:06 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		find_space(t_map *fmap)
{
	int i;

	i = 0;
	if (fmap->w >= 5)
		i = 40;
	if (fmap->w >= 10)
		i = 30;
	if (fmap->w >= 20)
		i = 20;
	if (fmap->w >= 25)
		i = 12;
	if (fmap->w >= 30)
		i = 10;
	if (fmap->w >= 40)
		i = 5;
	if (fmap->w >= 15 && fmap->h <= 15)
		i = 60;
	if (fmap->w >= 18 && fmap->h <= 25)
		i = 40;
	if (fmap->w >= 18 && fmap->h <= 15)
		i = 30;
	if (fmap->w >= 20 && fmap->h <= 30)
		i = 25;
	return (i);
}

int		create_box(t_map *fmap)
{
	int wd;
	int	ht;
	int val;

	fmap->x1 = 0;
	fmap->y1 = 0;
	ht = 0;
	val = find_space(fmap);
	while (ht != fmap->h)
	{
		fmap->x1 = 0;
		wd = 0;
		while (wd != fmap->w)
		{
			fmap->x1 += val;
			fmap->xgrid[ht][wd] = fmap->x1;
			fmao->ygrid[ht][wd] = fmap->y1;
			wd++;
		}
		fmap->y1 += val;
		height++;
	}
	return (0);
}

int		edit_box(t_map *fmap)
{
	int wd;
	int ht;

	ht = 0;
	while (ht != fmap->h)
	{
		fmap->x1 = 0;
		wd = 0;
		while (wd != fmap->w)
		{
			fmap->xgrid[ht][wd] = fmap->xgrid[ht][wd] - fmap->map[ht][wd];
			fmap->ygrid[h][wd] = fmap->ygrid[ht][wd] + ((fmap->xgrid[ht][wd] +
						fmap->map[ht][wd]) / 2);
			wd++;
		}
		ht++;
	}
	return (0);
}

int		centre_box(t_map *fmap)
{
	int wd;
	int ht;

	ht = 0;
	while (ht != fmap->h)
	{
		fmap->x1 = 0;
		wd = 0;
		while (wd != fmap->w)
		{
			fmap->xgrid[ht][wd] += (fmap->w_width / fmap->w) + (fmap->w_width
					* .05);
			fmap->ygrid[ht][wd] += (fmap->w_height / fmap->h) + 
				(fmap->w_height * .0925);
			mlx_pixel_put(fmap->mlx, fmap->window,
					fmap->xgrid[ht][wd], fmap->ygrid[ht][wd], fmap->color);
			wd++;
		}
		ht++;
	}
	return (0);
}
