/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_otuls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:24:50 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/24 00:33:51 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_is_sort(t_PILE *pile)
{
	int i;

	i = 1;
	while (pile->next)
	{
		if (pile->num < pile->next->num)
			return (0);
		pile = pile->next;
	}
	return (1);
}

void	pos_min_max(t_PILE **pile, int *min, int *max)
{
	int i;
	int j;
	t_PILE *tmp;

	tmp = *pile;
	*max = tmp->num;
	*min = tmp->num;
	i = 1;
	j = 1;
	while (tmp->next)
	{
		if (*max < tmp->num)
		{
			*max = tmp->num;
			i++;
		}
		if (*min > tmp->num)
		{
			*min = tmp->num;
			j++;
		}
		tmp = tmp->next;
	}
	*max = i;
	*min = j;
}

void	ft_index(t_PILE **pile)
{
	int i;
	t_PILE *tmp;

	tmp = *pile;
	i = 0;
	while (tmp->next)
	{
		tmp->index = i;
		tmp = tmp->next;
	}
}

int	get_index_min(t_PILE **pile)
{
	t_PILE *tmp;
	int min;
	int *index_min;

	ft_index(pile);
	tmp = *pile;
	min = tmp->num;
	index_min = 0;
	while (tmp->next)
	{
		if (min < tmp->num)
		{
			min = tmp->num;
			*index_min = tmp->index;
		}
		tmp = tmp->next;
	}
	return (*index_min);
}

