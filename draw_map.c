/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:39:13 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/21 09:10:54 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	veryfyline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isletter(str[i]))
		{
			if (str[i] == 'G')
				break ;
			ft_putendl("Error: line contains alphabetic characters");
			exit(0);
		}
		if ((str[i] == '-' &&(!(ft_isdigit(str[i + 1])))) || str[i] == '\t')
		{
			ft_putendl("Error : line contains tabs or no digit after minus");
			exit(0);
		}
		i++;
	}
}

void	verify_width(int fd, int wd, int twd)
{
	char *str;
	char **str1;

	if (get_next_line(fd, &str) > 0)
	{
		verifyline(str);
		if (!(str1 = ft_strsplit(str, ' ')))
		{
			ft_putendl("Error: unable to split line");
			exit(0);
		}
		if (!(twd = ft_strlenarr(str1)))
		{
			ft_putendl("Error: incorrect width");
			exit(0);
		}
		free(str);
		free(str1);
	}
}

void	verify_file(int fd, char *file)
{
	int wd;
	int twd;

	wd = 0;
	twd = 0;
	if (ft_strstr(filename, ".fdf") == 0)
	{
		ft_putendl("Error: Incorrect filename");
		exit(0);
	}
	verify_width(fd, wd, twd);
	close(fd);
}

int		**createmap(t_map fmaplist)
{
	int **map;
	int amnt;

	map = (int **)ft_memalloc(sizeof(int *) *fmaplist->h);
	amnt = fmaplist->h - 1;
	while (amnt >= 0)
	{
		map[amnt] = 0;
		amnt--;
	}
	return (map);
}

int		**draw_map(int fd, t_map *fmap)
{
	char *str;
	int	i;

	i = 0;
	while (i != fmap->h + 1)
	{
		if (get_next_line(fd, &str) > 0)
		{
			fmap->map[i] = strtointcopy(str);
			ft_bzero(str, ft_strlen(str));
			free(str);
		}
		i++;
	}
	close(fd);
	return (fmap->map);
}
