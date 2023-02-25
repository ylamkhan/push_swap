/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otuls_sort_100.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:39:25 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/22 16:37:29 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_exist(t_PILE *pile_a, int *tab)
{
	int i;

	i = 0;
	while(pile_a)
	{
		if (pile_a->num <= tab[i])
			return (1);
		i++;
		pile_a =  pile_a->next;
	}
	return 0;
}

void	find_next_elem(t_PILE *pile_a, int *tab, int end)
{
	int i;
	int j;
	int k;
	t_PILE *tmp;

	tmp = pile_a;
	i = 0;
	while (pile_a)
	{
		if(pile_a->num <= tab[end])
			break;
		pile_a = pile_a->next;
		i++;
	}
	j = 0;
	k = 0;
	while(tmp)
	{
		if(tmp->num <= tab[end])
			k = j;
		tmp = tmp->next;
		j++;
	}
	if (i > k)
		ft_rra_rrb(&pile_a, 'a');
	else
		ft_ra_rb(&pile_a, 'a');
}

// void	push_to_b(t_PILE **pile_a, t_PILE *pile_b)
// {
// 	int	*tab;
// 	int end;

// 	tab = get_tab_sorted(*pile_a);
// 	while (ft_lstsize(pile_a) != 0)
// 	{
// 		while(if_exist(pile_a, tab))
// 		{
// 			if (pile_a->num <= tab[end])
// 			{
// 				ft_pb(pile_b, pile_a);
// 				if ()
// 			}
// 			else
// 				find_next_elem(*pile_a, tab, end);
// 		}
// 	}

// }
