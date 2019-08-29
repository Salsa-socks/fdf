/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:54:45 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/21 12:55:02 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	info_str(t_map *fmap)
{
	mlx_string_put(fmap->mlx, fmap->window,10, 30, 0x98FB98, ".........");
	mlx_string_put(fmap->mlx, fmap->window,10, 45, 0x98FB98, "Exit: ESC");
	mlx_string_put(fmap->mlx, fmap->window,10, 60, 0x98FB98, "Z axis T");
	mlx_string_put(fmap->mlx, fmap->window,10, 75, 0x98FB98, "Color: Q,W,E,R");
	mlx_string_put(fmap->mlx, fmap->window,10, 90, 0x98FB98, ".........");
}

int		color_key(int key, t_map *fmap)
{
	if (key == 12)
	{
		mlx_clear_window(fmap->mlx, fmap->window);
		fmap->color = 0x0b40e7;
		draw_grid(fmap);
	}
	if (key == 13)
	{
		mlx_clear_window(fmap->mlx, fmap->window);
		fmap->color = 0xfff2345;
		draw_grid(fmap);
	}
	if (key == 14)
	{
		mlx_clear_window(fmap->mlx, fmap->window);
		fmap->color = 0x11c300;
		draw_grid(fmap);
	}
	if (key == 15)
	{
		mlx_clear_window(fmap->mlx, fmap->window);
		fmap->color = 0xffffff;
		draw_grid(fmap);
	}
	return (0);
}

int		escclose(int key, t_map *fmap)
{
	if (!(fmap->window))
		return (0);
	if (key == 12 || key == 13 || key == 14 || key == 15)
	color_key(key, fmap);
	if (key == 17)
	{
		mlx_clear_window(fmap->mlx, fmap->window);
		build_z(key, fmap);
	}
	if (key == 53)
	{
		ft_putendl("Closing Program");
		exit(0);
	}
	return (0);	
}
