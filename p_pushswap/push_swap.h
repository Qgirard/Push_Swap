/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:22:16 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/15 17:02:06 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

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
int				makerb(t_lcheck **tampon, t_moves **actions);
int				make_order_in_pile(t_lcheck **stock, t_moves **actions, int j,
				int var);
int				countlist(t_lcheck **stock);
int				makerra(t_lcheck **stock, t_moves **actions);
int				makerrb(t_lcheck **tampon, t_moves **actions);
int				ft_swap_stock(t_lcheck **stock, t_moves **actions, char c);
int				mediane(t_lcheck **stock, int var);
int				stockactions(t_moves **actions, int var);
int				tri2_3nbs(t_lcheck **stock, t_lcheck **tampon,
				t_moves **actions, char c);
int				tri_when_pile_a(t_lcheck **stock, t_moves **actions, int var);
int				tri_pile_b(t_lcheck **tampon, t_moves **actions, int var);
void			printactions(t_moves **actions);
int				checksort(t_lcheck **stock);
int				recup_in_b(t_lcheck **stock, t_lcheck **tampon,
				t_moves **actions, int var);
int				recup_in_a(t_lcheck **stock, t_lcheck **tampon,
				t_moves **actions, int var);
int				push_rotate(t_lcheck **stock, t_lcheck **tampon,
				t_moves **actions, int var);
int				rev_push_rotate(t_lcheck **stock, t_lcheck **tampon,
				t_moves **actions, int var);
int				reduce_actions(t_moves **actions);
void			reduce_rotatea(t_moves **tmp, t_moves **ptr);
void			reduce_morerotatea(t_moves **tmp, t_moves **ptr);
void			reduce_rotateb(t_moves **tmp, t_moves **ptr);
void			reduce_morerotateb(t_moves **tmp, t_moves **ptr);

#endif
