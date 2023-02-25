/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:09:34 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/22 17:41:46 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"

void	ft_sort(t_PILE **pile_a, t_PILE **pile_b)
{
	int size;

	if (!pile_is_sort(*pile_a))
		return;
	size = ft_lstsize(*pile_a);
	if (size <= 2)
		sort_2(pile_a);
	else if (size == 3)
		sort_3(pile_a);
	else if (size <= 5)
		sort_4_5(pile_a, pile_b);
	else if (size <= 100)
		sort_100(pile_a, pile_b, 4);
	else
		sort_100(pile_a, pile_b, 8);
}
