/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:22:16 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 16:27:54 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libftprintf/ft_printf.h"

typedef struct	s_lcheck
{
	int				i;
	struct s_lcheck	*next;
}				t_lcheck;

typedef struct	s_temp
{
	int				x;
	struct s_temp	*next;
	struct s_temp	*prev;
}				t_temp;

int				putlists(t_lcheck **stock, char *str);
int				freewhenerror(t_lcheck **stock);
int				push_swap(t_lcheck **stock, t_temp **tampon);
int				scdelist(t_temp **tampon, t_lcheck **stock);
int				freend(t_lcheck **stock, t_temp **tampon);

#endif
