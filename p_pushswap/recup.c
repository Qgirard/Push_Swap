/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:44:37 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/08 14:34:52 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		recup_in_a(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int		i;

	i = 0;
	while (i < var && (*stock))
	{
		if (!pushb(stock, tampon, actions))
			return (0);
		i++;
	}
	return (1);
}

int		recup_in_b(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int		i;

	i = 0;
	while (i < var && (*tampon))
	{
		if(!pusha(stock, tampon, actions))
			return (0);
		i++;
	}
	return (1);
}
