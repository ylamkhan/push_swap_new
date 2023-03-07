/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:51:43 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 02:30:57 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	last_num_pile_a(t_PILE *pile)
{
	if (!pile)
		return (0);
	while (pile->next)
		pile = pile->next;
	return (pile->num);
}

static	int	get_max(t_PILE *pile)
{
	int	max;

	if (!pile)
		return (0);
	max = pile->num;
	while (pile)
	{
		if (max < pile->num)
			max = pile->num;
		pile = pile->next;
	}
	return (max);
}

static	void	min_puch_to_a_inf_mid(t_PILE **pile_a, t_PILE **pile_b,
	int *down)
{
	while (get_index_max(pile_b))
	{
		if (!*down || last_num_pile_a(*pile_a) < (*pile_b)->num)
		{
			ft_pa(pile_b, pile_a);
			ft_ra_rb(pile_a, 'a');
			(*down)++;
		}
		else
			ft_ra_rb(pile_b, 'b');
	}
}

static	void	min_puch_to_a_sup_mid(t_PILE **pile_a, t_PILE **pile_b,
	int *down)
{
	while (get_index_max(pile_b))
	{
		if (!*down || last_num_pile_a(*pile_a) < (*pile_b)->num)
		{
			ft_pa(pile_b, pile_a);
			ft_ra_rb(pile_a, 'a');
			(*down)++;
		}
		else
			ft_rra_rrb(pile_b, 'b');
	}
}

void	ft_puch_to_a(t_PILE **pile_a, t_PILE **pile_b)
{
	int	down;
	int	mid;

	down = 0;
	ft_index(*pile_b);
	while (*pile_b)
	{
		mid = ft_lstsize(*pile_b) / 2;
		if (get_index_max(pile_b) > mid)
			min_puch_to_a_sup_mid(pile_a, pile_b, &down);
		else
			min_puch_to_a_inf_mid(pile_a, pile_b, &down);
		ft_pa(pile_b, pile_a);
		while (down && get_max(*pile_b) < last_num_pile_a(*pile_a))
		{
			ft_rra_rrb(pile_a, 'a');
			down--;
		}
	}
	while (down)
	{
		ft_rra_rrb(pile_a, 'a');
		down--;
	}
}
