/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:39:13 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/20 11:06:17 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		strlen2(char **str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

		}
		if ((str[i] == '-' &&(!(ft_isdigit(str[i + 1])))) || str[i] == '\t')
			ft_putendl("Error : line contains tabs or no digit after minus");
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
			ft_putendl("Error: unable to split line");
		if (!(twd = strlen2(str1)))
			ft_putendl("Error: incorrect width");
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
		ft_putendl("Error: Incorrect filename");
	verify_width(fd, wd, twd);
	close(fd);
}

int		**draw_map(int fd, f_map *fmap)
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
