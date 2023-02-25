/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:52:51 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/10 18:49:14 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_checker_min(t_PILE **pile_a, t_PILE **pile_b)
{
	if (get_next_line(0) == "sa")
		ft_realise_sa_sb(pile_a);
	else if (get_next_line(0) == "sb")
		ft_realise_sa_sb(pile_b);
	else if (get_next_line(0) == "ss")
		ft_realise_sa_sb(pile_a, pile_a);
	else if (get_next_line(0) == "ra")
		ft_realise_ra_rb(pile_a);
	else if (get_next_line(0) == "rb")
		ft_realise_ra_rb(pile_b);
	else if (get_next_line(0) == "rr")
		ft_realise_rr(pile_a, pile_b);
	else if (get_next_line(0) == "rra")
		ft_realise_rra_rrb(pile_a);
	else if (get_next_line(0) == "rrb")
		ft_realise_rra_rrb(pile_b);
	else if (get_next_line(0) == "rrr")
		ft_realise_rrr(pile_b);
	else if (get_next_line(0) == "pa")
		ft_realise_pa(pile_a, pile_b);
	else if (get_next_line(0) == "pb")
		ft_realise_rrr(pile_b, pile_a);
	else
		return (0);
	return (1);
}

void	ft_checker(t_PILE **pile_a, t_PILE **pile_b)
{
	int i;

	i = 1;
	while (i)
		i = ft_checker_min(pile_a, pile_b);
	if (ft_check_pile_sort(pile_a) && !ft_lstsize1(*pile_b))
		write(1, "ok\n", 3);
	else
		write (1, "ko\n", 3);

}
