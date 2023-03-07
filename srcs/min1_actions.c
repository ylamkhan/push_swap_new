/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min1_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:26:28 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/06 02:40:26 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rb(t_PILE **pile, char name)
{
	if (!*pile)
		return ;
	ft_ra_rb_min(pile);
	if (name == 'a')
	{
		write(1, "ra\n", 3);
		return ;
	}
	if (name == 'b')
	{
		write(1, "rb\n", 3);
		return ;
	}
}

void	ft_rr(t_PILE **pile_a, t_PILE **pile_b)
{
	if (!(*pile_a) || !(*pile_b))
		return ;
	ft_ra_rb_min(pile_a);
	ft_ra_rb_min(pile_b);
	write(1, "rr\n", 3);
}

void	ft_pa(t_PILE **pile_b, t_PILE **pile_a)
{
	if (!*pile_b)
		return ;
	ft_pa_pb_min(pile_b, pile_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_PILE **pile_a, t_PILE **pile_b)
{
	if (!*pile_a)
		return ;
	ft_pa_pb_min(pile_a, pile_b);
	write(1, "pb\n", 3);
}
