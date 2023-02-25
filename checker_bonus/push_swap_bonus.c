/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:32:52 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/10 18:50:43 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_afficher(t_PILE **pile)
{
	t_PILE	*node;

	printf("\n\n");
	node = *pile;
	while (node)
	{
		printf("%d\n", node->num);
		(node) = (node)->next;
	}
	printf("\n");
}
