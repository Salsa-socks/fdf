/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:29:59 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/20 13:30:47 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlenarr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
