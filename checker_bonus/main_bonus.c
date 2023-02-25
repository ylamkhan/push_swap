/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:48:44 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/10 18:50:36 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	int		d;
	int		size_pile;
	t_PILE	*pile_b;
	t_PILE	*pile_a;

	if (ac > 1)
	{
		pile_a = NULL;
		pile_b = NULL;
		ft_init(ac, av, &pile_a);
		ft_checker(pile_a, pile_b);
		return (0);
	}
	return (0);
}

int	ft_check_pile_sort(t_PILE **pile_a)
{
	t_PILE	*temp;

	temp = (*pile_a);
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_stock_pile_a1(int valeur, t_PILE **pile_a)
{
	t_PILE	*temp;
	t_PILE	*new;

	temp = (*pile_a);
	while (temp)
	{
		if (temp->num == valeur)
			return (0);
		temp = temp->next;
	}
	new = ft_new_elemment(valeur);
	(*pile_a) = ft_push(pile_a, new);
	return (1);
}

int	ft_is_not_digitl(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if ((str[i] == '+' || str[i] == '-') && !str[i + 1])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_is_not_digitl(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_init(int ac, char **av, t_PILE **pile_a)
{
	char	**arg;
	int		i;
	int		j;
	int		d;

	i = 1;
	while (i < ac)
	{
		arg = ft_split(av[i++], ' ');
		if (!arg[0])
			return (0);
		j = 0;
		while (arg[j])
		{
			if (ft_check(arg[j]) == 0)
				return (0);
			else
			{
				d = ft_stock_pile_a1(ft_atoi(arg[j++]), pile_a);
				if (d == 0)
					return (0);
			}
		}
	}
	return (1);
}
