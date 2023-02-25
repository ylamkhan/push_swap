/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:56:23 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/24 00:54:34 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
	int num;
	int index;
	struct data *next;
}t_PILE;

/*libft*/
void		ft_lstadd_front(t_PILE **lst, t_PILE *new);
int			ft_lstsize(t_PILE *lst);
void		ft_lstadd_back(t_PILE  **lst, t_PILE *new);
int			ft_lstsize(t_PILE *lst);
t_PILE		*ft_lstnew(int content);
/*les actions*/
void		ft_sa_sb(t_PILE **pile, char name);
void		ft_ss(t_PILE **pile_a, t_PILE **pile_b);
void		ft_rra_rrb(t_PILE **pile, char name);
void		ft_rrr(t_PILE **pile_a, t_PILE **pile_b);
void		ft_ra_rb(t_PILE **pile, char name);
void		ft_rr(t_PILE **pile_a, t_PILE **pile_b);
void		ft_pa(t_PILE **pile_a, t_PILE **pile_b);
void		ft_pb(t_PILE **pile_b, t_PILE **pile_a);
/*min des actions*/
void		ft_sa_sb_min(t_PILE **pile);
void		ft_ra_rb_min(t_PILE **pile);
void		ft_pa_pb_min(t_PILE **pile1, t_PILE **pile2);
/* min_actions*/
void		pos_min_max(t_PILE **pile, int *min, int *max);
/*sort*/
void		sort_2(t_PILE **pile_a);
void		sort_3(t_PILE **pile);
void		sort_4_5(t_PILE **pile_a, t_PILE **pile_b);
void		ft_pa_pb_min(t_PILE **pile1, t_PILE **pile2);
void		ft_push_to_b(t_PILE **pile_a, t_PILE **pile_b, int n);
void		sort_100(t_PILE **pile_a, t_PILE **pile_b, int n);
/*sort_otuls*/
int			pile_is_sort(t_PILE *pile);
void		ft_ra_rb_min(t_PILE **pile);
void		ft_pa_pb_min(t_PILE **pile1, t_PILE **pile2);
int			get_index_min(t_PILE **pile);
/*outils_main*/
void		ft_sort(t_PILE **pile_a, t_PILE **pile_b);
/*main*/
int			ft_check_pile_sort(t_PILE **pile_a);
int			ft_stock_pile_a1(int valeur, t_PILE **pile_a);
int			ft_is_not_digitl(char c);
int			ft_check(char *str);
int			ft_init(int ac, char **av, t_PILE **pile_a);
/* pile_to_tab.c*/
int			*remplire_tab(t_PILE **pile, int size);
void		ft_swap(int *a, int *b);
int			*swap_tab(int *tab, int size);

/* outils_libft*/
char		**ft_split(char const *s, char c);

# endif
