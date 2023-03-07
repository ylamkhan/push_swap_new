/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:56:23 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 22:12:46 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<limits.h>

typedef struct data
{
	int			num;
	int			index;
	struct data	*next;
}t_PILE;

/*libft*/
void		ft_lstadd_front(t_PILE **lst, t_PILE *new);
t_PILE		*ft_lstlast(t_PILE *lst);
void		ft_lstadd_back(t_PILE **lst, t_PILE *new);
int			ft_lstsize(t_PILE *lst);
t_PILE		*ft_lstnew(int content);
/*actions*/
void		ft_sa_sb(t_PILE **pile, char name);
void		ft_ss(t_PILE **pile_a, t_PILE **pile_b);
void		ft_rra_rrb_min(t_PILE **pile);
void		ft_rra_rrb(t_PILE **pile, char name);
void		ft_rrr(t_PILE **pile_a, t_PILE **pile_b);
/*main*/
int			ft_check_pile_sort(t_PILE **pile_a);
int			ft_stock_pile_a1(int valeur, t_PILE **pile_a);
int			ft_is_not_digitl(char c);
/*min_action*/
void		ft_sa_sb_min(t_PILE **pile);
void		ft_ra_rb_min(t_PILE **pile);
void		ft_pa_pb_min(t_PILE **pile1, t_PILE **pile2);
/*min1_actions*/
void		ft_ra_rb(t_PILE **pile, char name);
void		ft_rr(t_PILE **pile_a, t_PILE **pile_b);
void		ft_pa(t_PILE **pile_b, t_PILE **pile_a);
void		ft_pb(t_PILE **pile_a, t_PILE **pile_b);
/*outils_libft*/
char		*ft_substr(char *s, int start, int len);
char		**ft_split(char *s, char c);
/*outils_main*/
void		ft_sort(t_PILE **pile_a, t_PILE **pile_b);
int			ft_check(char *str);
int			ft_init(int ac, char **av, t_PILE **pile_a);
/*outils*/
int			ft_get_valeur_index(t_PILE *pile, int index);
void		ft_push_to_b(t_PILE **pile_a, t_PILE **pile_b, int n);
/*outils1*/
void		ft_puch_to_a(t_PILE **pile_a, t_PILE **pile_b);
/*outils2_libft*/
int			ft_isdigit(int c);
int			ft_atoi(char *str);
char		*ft_strdup(char *s1);
int			ft_strlen(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
/*outils2*/
int			get_index_max(t_PILE **pile);
void		pos_max_1(t_PILE **pile, int pos_min);
void		pos_max_2(t_PILE **pile, int pos_min);
/*push_to_tab*/
int			*remplire_tab(t_PILE **pile, int size);
void		ft_swap(int *a, int *b);
int			*swap_tab(int *tab, int size);
/*push_swap*/
int			pile_is_sort(t_PILE *pile);
void		pos_min_max(t_PILE **pile, int *min, int *max);
void		ft_index(t_PILE *pile);
int			get_index_min(t_PILE **pile);
/*sort.c*/
void		sort_2(t_PILE **pile_a);
void		sort_3(t_PILE **pile);
void		sort_4_5(t_PILE **pile_a, t_PILE **pile_b);
void		sort_100(t_PILE **pile_a, t_PILE **pile_b, int n);

#endif
