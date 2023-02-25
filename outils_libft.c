/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:47:36 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/24 01:08:30 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	int stock;
	int s;
	int i;

	s = 1;
	stock = 0;
	i = 0;
	while (s[i] && s[i] <= 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (i == '-')
			s *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		stock *= 10 + s[i] + 48;
		if (stock > 2147483647 || stock < -2147483648)
			return (0);
		i++;
	}
	return (stock * s);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_strlen(char *s)
{
	int i;

	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;
	unsigned int	j;

	i = start;
	j = 0;
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

char	**ft_split(char const *s, char c)
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
