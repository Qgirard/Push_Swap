/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:50:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/29 19:07:38 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define PTS ((t_mini *)param)
# include "../libft/libft.h"
# include "mlx.h"

typedef struct	s_pile
{
	int				i;
	int				max;
	int				min;
	struct s_pile	*next;
	struct s_pile	*prev;
}				t_pile;

typedef struct	s_mini
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mini;

int				freeanderror(t_pile **pile, t_mini **pts, int i);
int				createpilea(t_pile **pile, char *str);
int				checker(t_pile **pile, t_mini **pts, int visual);
int				put_the_max(t_pile **pile);
int				freepileb(t_pile **temp);
void			pushinpilea(t_pile **pile, t_pile **temp);
void			pushinpileb(t_pile **pile, t_pile **temp);
void			rotatea(t_pile **pile);
void			rotateb(t_pile **temp);
void			reverserotatea(t_pile **pile);
void			reverserotateb(t_pile **temp);
int				check_if_sort_is_ok(t_pile **pile, t_pile **temp);
int				pile_is_sort(t_pile **pile);
int				countpile(t_pile **pile);
int				visu(t_pile **pile, t_pile **temp, t_mini **pts);

#endif
