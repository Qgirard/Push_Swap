/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:44:37 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/06 18:09:22 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		recup_in_b(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	while (var > 0)
	{
		if(!pusha(stock, tampon, actions))
			return (0);
		var--;
	}
	return (1);
}
