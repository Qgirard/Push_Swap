/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:21:51 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 16:39:45 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checkpile(char *str, t_lcheck **stock)
{
	t_lcheck *tmp;

	if ((*stock))
	{
		tmp = (*stock);
		while (tmp)
		{
			if (ft_atoi(str) == tmp->i)
				return (0);
			tmp = tmp->next;
		}
	}
	if (ft_strisnumber(str))
	{
		if (!putlists(stock, str))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int			i;
	t_lcheck	*stock;
	t_temp		*tampon;

	i = 1;
	stock = NULL;
	tampon = NULL;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		if (!checkpile(argv[i], &stock))
			return (freewhenerror(&stock));
		i++;
	}
	push_swap(&stock, &tampon);
	/*while (tampon)
	{
		ft_printf("%d\n", tampon->x);
		tampon = tampon->next;
	}*/
	/*while (stock)
	{
		ft_printf("%d\n", stock->i);
		stock = stock->next;
	}*/
	freend(&stock, &tampon);
	return (0);
}
