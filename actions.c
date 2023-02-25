/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:53:34 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/24 00:38:22 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"

void	ft_sa_sb(t_PILE **pile, char name)
{
	if (!*pile)
		return;
	ft_sa_sb_min(pile);
	if (name == 'a')
	{
		write(1, "sa\n", 3);
		return;
	}
	if (name == 'b')
	{
		write(1, "sb\n", 3);
		return;
	}
}

void	ft_ss(t_PILE **pile_a, t_PILE **pile_b)
{
	if (!*pile_a || !*pile_b)
		return;
	ft_sa_sb_min(pile_a);
	ft_sa_sb_min(pile_b);
	write(1, "ss\n", 3);
}

void	ft_rra_rrb_min(t_PILE **pile)
{
	t_PILE	*tmp;
	t_PILE	*tmp1;

	tmp = (*pile);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(pile, tmp1);
}

void	ft_rra_rrb(t_PILE **pile, char name)
{
	if (!*pile)
		return
	ft_rra_rrb_min(pile);
	if (name == 'a')
	{
		write(1, "rra\n", 3);
		return;
	}
	if (name == 'b')
	{
		write(1, "rrb\n", 3);
		return;
	}
}

void	ft_rrr(t_PILE **pile_a, t_PILE **pile_b)
{
	if (!*pile_a || !*pile_b)
		return;
	ft_ra_rb_min(pile_a);
	ft_ra_rb_min(pile_b);
	write(1, "rr\n", 3);
}

void	ft_ra_rb(t_PILE **pile, char name)
{
	if (!*pile)
		return;
	ft_ra_rb_min(pile);
	if (name == 'a')
	{
		write(1, "ra\n", 3);
		return;
	}
	if (name == 'b')
	{
		write(1, "rb\n", 3);
		return;
	}
}

void	ft_rr(t_PILE **pile_a, t_PILE **pile_b)
{
	if (!(*pile_a) || !(*pile_b))
		return;
	ft_ra_rb_min(pile_a);
	ft_ra_rb_min(pile_b);
	write(1, "rr\n", 3);
}

void	ft_pa(t_PILE **pile_a, t_PILE **pile_b)
{
	if (!*pile_a)
		return;
	ft_pa_pb_min(pile_a, pile_b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_PILE **pile_b, t_PILE **pile_a)
{
	if (!*pile_b)
		return;
	ft_pa_pb_min(pile_b, pile_a);
	write(1, "pb\n", 3);
}
