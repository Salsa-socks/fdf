/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 08:43:43 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/21 08:44:57 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapint(int *c, int *v)
{
	int tmp;

	tmp = *c;
	*c = *v;
	*v = tmp;
}
