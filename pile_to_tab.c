/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:04:18 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/22 17:45:53 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"

int	*remplire_tab(t_PILE **pile, int size)
{
	int *tab;
	t_PILE *tmp;
	int	i;

	tab = malloc(sizeof(int)*size);
	if (tab == NULL)
		return (0);
	i = 0;
	tmp = *pile;
	while (tmp->next)
	{
		tab[i++] = tmp->num;
		tmp = tmp->next;
	}
	tab = swap_tab(tab, size);
	return (tab);
}

void ft_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int *swap_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if(tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}


