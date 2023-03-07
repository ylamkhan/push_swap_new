/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:39:17 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/06 02:06:45 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sa_sb(t_PILE **pile)
{
	if (ft_lstsize(*pile) < 2)
		return ;
	ft_sa_sb_min(pile);
}

void	ft_ss(t_PILE **pile_a, t_PILE **pile_b)
{
	if (!*pile_a || !*pile_b)
		return ;
	ft_sa_sb_min(pile_a);
	ft_sa_sb_min(pile_b);
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
	tmp1->next = NULL;
	ft_lstadd_front(pile, tmp1);
}

void	ft_rra_rrb(t_PILE **pile)
{
	t_PILE	*tmp;
	t_PILE	*tmp1;

	if (ft_lstsize(*pile) < 2)
		return ;
	tmp = (*pile);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	tmp->next = NULL;
	tmp1->next = NULL;
	ft_lstadd_front(pile, tmp1);
}

void	ft_rrr(t_PILE **pile_a, t_PILE **pile_b)
{
	if (ft_lstsize(*pile_a) > 1)
		ft_ra_rb_min(pile_a);
	if (ft_lstsize(*pile_b) > 1)
		ft_ra_rb_min(pile_b);
}
