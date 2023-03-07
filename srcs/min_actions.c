/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:19:48 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/06 02:23:50 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb_min(t_PILE **pile)
{
	int	tmp;

	tmp = (*pile)->num;
	(*pile)->num = (*pile)->next->num;
	(*pile)->next->num = tmp;
}

void	ft_ra_rb_min(t_PILE **pile)
{
	t_PILE	*tmp;

	tmp = *pile;
	*pile = (*pile)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile, tmp);
}

void	ft_pa_pb_min(t_PILE **pile1, t_PILE **pile2)
{
	t_PILE	*tmp;

	tmp = *(pile1);
	(*pile1) = (*pile1)->next;
	tmp->next = NULL;
	ft_lstadd_front(pile2, tmp);
}
