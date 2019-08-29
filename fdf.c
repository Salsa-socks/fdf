/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:36:38 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/23 10:53:21 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_map *fmap;
	int fd;

	if (ac != 2)
	{
		ft_putendl("Error: One argument needed");
		exit(0);	
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("Error: failed to open file");
		exit(0);
	}
	if (!(fmap = (t_map *)ft_memalloc(sizeof(t_map))))
	{
		ft_putendl("Error: failed to memalloc");
		exit(0);
	}
	fmap->w_width = 1200;
	fmap->w_height = 1200;
	fmap->color = 0xffffff;
	verify_file(fd, av[1]);
	fd = open(av[1], O_RDONLY);
	line_h(fd, fmap);
	fmap->map = createmap(fmap);
	fd = open(av[1], O_RDONLY);
	fmap->map = draw_map(fd, fmap);
	make_window(fmap);
	fd = fmap->h - 1;
	while (fd >= 0)
		free(fmap->map[fd--]);
	free(fmap->map);
}