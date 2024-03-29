/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creategrid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:29:47 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/23 14:17:26 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int *strtointcopy(char *str)
{
	int *res;
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	res = ft_memalloc((len) * sizeof(int));
	while (i < len)
	{
		if (!(ft_isspace(str[i])) && str[i] != '\0')
		{
			str[j] = ft_gatoi(&str[i]);
			i += ft_nbrlen(str[i]);
			j++;
		}
		else
			i++;
	}
	j = 0;
	while (j < 11)
		j++;
	return (res);
}

int			**make_map(int fd, t_map *fmap)
{
	char 	*str;
	int		i;

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
	return(fmap->map);
}

void		line_h(int fd, t_map *fmlist)
{
	char 	**bigline;
	int		wth;
	int		i;
	char	*line;

	wth = 0;
	i = 0;
	if (get_next_line(fd, &line) > 0)
	{
		bigline = ft_strsplit(line, ' ');
		fmlist->w = ft_strlenarr(bigline);
		while (bigline[i])
			free(bigline[i++]);
		free(bigline);
		free(line);
		wth++;
	}
	while (get_next_line(fd, &line) > 0)
	{
		wth++;
		free(line);
	}
	fmlist->h = wth;
	close(fd);
}

int			**creategrid(t_map *fmlist)
{
	int val;
	int **grid;

	grid = (int **)ft_memalloc(sizeof(int *) *fmlist->h);
	val = fmlist->h - 1;
	while (val >= 0)
	{
		grid[val] = (int *)ft_memalloc(sizeof(int) * fmlist->w);
		val--;
	}
	return (grid);
}
