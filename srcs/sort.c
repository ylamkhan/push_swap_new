/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:51:00 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 02:26:26 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_PILE **pile_a)
{
	if (!*pile_a)
		return ;
	ft_sa_sb(pile_a, 'a');
}

void	sort_3(t_PILE **pile)
{
	int	pos_min;
	int	pos_max;

	if (pile_is_sort(*pile))
		return ;
	pos_min_max(pile, &pos_min, &pos_max);
	if (pos_max == 1)
		pos_max_1(pile, pos_min);
	else if (pos_max == 2)
		pos_max_2(pile, pos_min);
	else
		ft_sa_sb(pile, 'a');
}

void	sort_4_5(t_PILE **pile_a, t_PILE **pile_b)
{
	int	mid;

	mid = ft_lstsize(*pile_a) / 2;
	while (ft_lstsize(*pile_a) > 3)
	{
		if (get_index_min(pile_a) > mid)
		{
			while (get_index_min(pile_a))
				ft_rra_rrb(pile_a, 'a');
		}
		else
		{
			while (get_index_min(pile_a))
				ft_ra_rb(pile_a, 'a');
		}
		ft_pb(pile_a, pile_b);
	}
	sort_3(pile_a);
	ft_pa(pile_b, pile_a);
	ft_pa(pile_b, pile_a);
}

void	sort_100(t_PILE **pile_a, t_PILE **pile_b, int n)
{
	ft_push_to_b(pile_a, pile_b, n);
	ft_puch_to_a(pile_a, pile_b);
}
