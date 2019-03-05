/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:22:16 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/05 14:17:24 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftprintf/ft_printf.h"

typedef struct	s_lcheck
{
	int				i;
	struct s_lcheck	*next;
	struct s_lcheck *prev;
}				t_lcheck;

typedef struct	s_moves
{
	int				sa;
	int				sb;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	struct s_moves	*next;
}				t_moves;

int				putlists(t_lcheck **stock, char *str);
int				freewhenerror(t_lcheck **stock, t_lcheck **tampon,
				t_moves **actions);
int				push_swap(t_lcheck **stock, t_lcheck **tampon,
				t_moves **actions, int var);
int				freend(t_lcheck **stock, t_lcheck **tampon, t_moves **actions);
int				pusha(t_lcheck **stock, t_lcheck **tampon, t_moves **actions);
int				pushb(t_lcheck **stock, t_lcheck **tampon, t_moves **actions);
int				makera(t_lcheck **stock, t_moves **actions);
int				countlist(t_lcheck **stock);
int				makerra(t_lcheck **stock, t_moves **actions);
int				mediane(t_lcheck **stock);
int				stockactions(t_moves **actions);
int				trinbs(t_lcheck **stock, t_moves **actions);
void			printactions(t_moves **actions);
int				checksort(t_lcheck **stock);

#endif
