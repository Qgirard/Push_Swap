/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:49:57 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/04 16:21:05 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		checker(char **str)
{
	int		i;

	i = 0;
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (checker(argv) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	write(2, "Error\n", 6);
	return (0);
}
