/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:45:57 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/06 03:35:21 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
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

/*actions*/

void			ft_sa_sb(t_PILE **pile);
void			ft_ss(t_PILE **pile_a, t_PILE **pile_b);
void			ft_rra_rrb_min(t_PILE **pile);
void			ft_rra_rrb(t_PILE **pile);
void			ft_rrr(t_PILE **pile_a, t_PILE **pile_b);

/*outils_actions*/

void			ft_sa_sb_min(t_PILE **pile);
void			ft_ra_rb_min(t_PILE **pile);
void			ft_pa_pb_min(t_PILE **pile1, t_PILE **pile2);
/*checker*/
int				ft_checker_min(t_PILE **pile_a, t_PILE **pile_b, char *str);
void			ft_checker(t_PILE **pile_a, t_PILE **pile_b);
/*libft*/
int				ft_isdigit(int c);
char			*ft_strdup(char *s1);
char			*get_next_line(int fd);
size_t			ft_strlen(char *s);
void			*ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char *s, char c);
int				ft_atoi(const char *str);
int				ft_lstsize1(t_PILE *lst);
int				ft_stock_pile_a(int ac, char **av, t_PILE **pile_a);
int				ft_check_pile_sort(t_PILE **pile_a);
int				ft_stock_pile_a1(int valeur, t_PILE **pile_a);
int				ft_is_not_digitl(char c);
int				ft_init(int ac, char **av, t_PILE **pile_a);
int				ft_check(char *str);
char			*ft_substr(char *s, unsigned int start, size_t len);
void			ft_lstadd_front(t_PILE **lst, t_PILE *new);
t_PILE			*ft_lstlast(t_PILE *lst);
void			ft_lstadd_back(t_PILE **lst, t_PILE *new);
int				ft_lstsize(t_PILE *lst);
t_PILE			*ft_lstnew(int content);
void			ft_ra_rb(t_PILE **pile);
void			ft_rr(t_PILE **pile_a, t_PILE **pile_b);
void			ft_pa(t_PILE **pile_b, t_PILE **pile_a);
void			ft_pb(t_PILE **pile_a, t_PILE **pile_b);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
