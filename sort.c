/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:51:00 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/24 00:36:47 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_PILE **pile_a)
{
	if (!*pile_a)
		return;
	ft_sa_sb(pile_a, 'a');
}

void	sort_3(t_PILE **pile)
{
	int pos_max;
	int pos_min;

	pos_min_max(pile, &pos_min, &pos_max);
	if (pos_max == 1)
	{
		if (pos_min == 2)
			ft_ra_rb(pile, 'a');
		else
		{
			ft_ra_rb(pile, 'a');
			ft_sa_sb(pile, 'a');
		}
	}
	else if(pos_max == 2)
	{
		if (pos_min == 1)
		{
			ft_sa_sb(pile, 'a');
			ft_ra_rb(pile, 'a');
		}
		else
			ft_rra_rrb(pile, 'a');
	}
	else
		ft_sa_sb(pile, 'a');
}

void	sort_4_5(t_PILE **pile_a, t_PILE **pile_b)
{
	int mid;
	int index_min;

	while (ft_lstsize(*pile_a) >= 3 )
	{
		mid = ft_lstsize(*pile_a)/2;
		if (get_index_min(pile_a) > mid)
		{
			while (get_index_min(pile_a))
				ft_rra_rrb(pile_a, 'a');
		}
		else
		{
			while (get_index_min(pile_a))
				ft_ra_rb(pile_a, 'a');
		}
		ft_pa(pile_a, pile_b);
		if ( ft_lstsize(*pile_a) == 3)
			sort_3(pile_a);
	}
	ft_pb(pile_b, pile_b);
	ft_pb(pile_b, pile_a);
}

int	ft_get_valeur_index(t_PILE *pile, int index)
{
	while (pile->next)
	{
		if (index == pile->index)
			return (pile->num);
		pile = pile->next;
	}
	return 0;
}

void	ft_push_to_b(t_PILE **pile_a, t_PILE **pile_b, int n)
{
	t_PILE *tmp;
	int *tab;
	int size;
	int k;
	int j;
	int i;

	k = 1;
	size = ft_lstsize(*pile_a);
	tab = remplire_tab(pile_a, size);
	while (ft_lstsize(*pile_a))
	{
		j = (size / n)*k;
		while(i < j)
		{
			if ((*pile_a)->num < tab[j])
			{
				ft_pb(pile_b, pile_a);
				i++;
			}
			else
				ft_ra_rb(pile_a, 'a');
		}
		k++;
	}
}

void	sort_100(t_PILE **pile_a, t_PILE **pile_b, int n)
{
	ft_push_to_b(pile_a, pile_b, n);
}
