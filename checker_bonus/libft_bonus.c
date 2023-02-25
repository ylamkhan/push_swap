/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:20:34 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/10 18:50:24 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;
	unsigned int	j;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) - start <= len)
		len = ft_strlen((s + start));
	p = (char *)malloc(len * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (j < len && *(s + i + j))
	{
		*(p + j) = *(s + i + j);
		j++;
	}
	*(p + j) = '\0';
	return (p);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	len;
	int	a;

	i = 0;
	len = 0;
	a = 1;
	while (s[i])
	{
		if (s[i] != c && a)
		{
			a = 0;
			len++;
		}
		if (s[i] == c)
			a = 1;
		i++;
	}
	return (len);
}

static int	ft_lencount(char const *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[*i])
	{
		if (s[*i] == c)
		{
			break ;
		}
		(*i)++;
		len++;
	}
	return (len);
}

static void	*freemove(char ***ptr, int d)
{
	int		i;
	char	**a;

	a = *ptr;
	i = 0;
	if (!a[d])
	{
		while (d >= 0)
		{
			free(a[d]);
			d--;
		}
		free(a);
		return (0);
	}
	return ((void *)1);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		d;
	char	**ptr;

	i = 0;
	d = 0;
	if (!s)
		return (NULL);
	ptr = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		ptr[d] = ft_substr(s, i, ft_lencount(s, c, &i));
		if (!freemove(&ptr, d))
			return (NULL);
		d++;
	}
	ptr[d] = NULL;
	return (ptr);
}

static int	ft_stock(int i, const char *str, int d)
{
	long	stock;

	stock = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			printf("Error\n");
			exit(1);
		}
		stock = stock * 10 + str[i] - 48;
		if (stock * d < INT32_MIN || stock * d > INT32_MAX)
		{
			printf("Error\n");
			//exit(1);
			return (0);
		}
		i++;
	}
	return (d * stock);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	stock;
	int			d;

	i = 0;
	stock = 0;
	d = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		d = (-1) * d;
		i++;
	}
	else if (str[i] == '+')
		i++;
	stock = ft_stock(i, str, d);
	return (stock);
}

int	ft_lstsize1(t_PILE *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_stock_pile_a(int ac, char **av, t_PILE **pile_a)
{
	char	**arg;
	int		i;
	int		j;
	int		stock;
				t_PILE *new;

	i = 1;
	while (i < ac)
	{
		arg = ft_split(av[i], ' ');
		j = 0;
		while (arg[j])
		{
			stock = ft_atoi(arg[j]);
			if (stock != 0)
			{
				new = ft_new_elemment(stock);
				(*pile_a) = ft_push(pile_a, new);
			}
			j++;
		}
		i++;
	}
	return (0);
}
