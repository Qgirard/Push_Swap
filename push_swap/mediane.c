/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:42:54 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/20 17:28:09 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		findmed(int **tab, int pivot)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	ft_putendl("YIPIKAI");
	while (j < pivot)
	{
		if ((*tab)[j] < (*tab)[pivot])
		{
			i++;
			ft_swap(&((*tab)[i]), &((*tab)[j]));
		}
		j++;
	}
	ft_swap(&((*tab)[i + 1]), &((*tab)[pivot]));
	if (i - 1 >= 0 && i - 1 != pivot)
		findmed(tab, i - 1);
	if (i + 1 < pivot)
		findmed(tab, i + 1);
	return (pivot / 2);
}

int		mediane(t_lcheck **stock)
{
	int			*tab;
	int			k;
	t_lcheck	*tmp;

	tab = NULL;
	k = 0;
	tmp = (*stock);
	if (!(tab = (int *)malloc(sizeof(int) * (countlist(stock)))))
		return (0);
	while (tmp)
	{
		tab[k] = tmp->i;
		k++;
		tmp = tmp->next;
	}
	k = tab[findmed(&tab, countlist(stock) - 1)];
	/*k = 0;
	while (k < countlist(stock))
	{
		ft_printf("%d\n", tab[k]);
		k++;
	}*/
	ft_printf("%d\n", k);
	free(tab);
	return (k);
}
