/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:45:57 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/02/09 16:29:03 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct test
{
	int			num;
	int			index;
	struct test	*next;
}				t_PILE;

/*main :*/
int				ft_stock_pile_a(int ac, char **av, t_PILE **pile_a);
int				ft_init(int ac, char **av, t_PILE **pile_a);
int				ft_check_pile_sort(t_PILE **pile_a);
//push_swap :
void			ft_afficher(t_PILE **pile);
/*actions :*/
void			ft_realise_sa_sb(t_PILE **pile);
void			ft_realise_ss(t_PILE **pile1, t_PILE **pile2);
void			ft_realise_ra_rb(t_PILE **pile);
void			ft_realise_rr(t_PILE **pile1, t_PILE **pile2);
void			ft_realise_rra_rrb(t_PILE **pile);
void			ft_realise_rrr(t_PILE **pile1, t_PILE **pile2);
void			ft_realise_pa(t_PILE **pile_a, t_PILE **pile_b);
void			ft_realise_pb(t_PILE **pile_b, t_PILE **pile_a);
t_PILE			*ft_new_elemment(int valeur);
t_PILE			*ft_push(t_PILE **pile_a, t_PILE *elemment);
t_PILE			*ft_pop(t_PILE **pile_a);
/*libft :*/
size_t			ft_strlen(char *s);
char			*ft_strchr(char *s, int c);
void			*ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s1);
int				ft_isdigit(int c);
int				ft_lstsize1(t_PILE *lst);
void			ft_lstadd_front(t_PILE **lst, t_PILE *new);
size_t			ft_strlen(char *s);
char			**ft_split(char *s, char c);
int				ft_atoi(const char *str);
/*++++++++++++get_next_line :*/
char			*get_next_line(int fd);

#endif
