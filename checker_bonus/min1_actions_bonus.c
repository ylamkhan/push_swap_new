/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min1_actions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:30:04 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/06 03:30:47 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_ra_rb(t_PILE **pile)
{
	if (!*pile)
		return ;
	ft_ra_rb_min(pile);
}

void	ft_rr(t_PILE **pile_a, t_PILE **pile_b)
{
	if (!(*pile_a) || !(*pile_b))
		return ;
	ft_ra_rb_min(pile_a);
	ft_ra_rb_min(pile_b);
}

void	ft_pa(t_PILE **pile_b, t_PILE **pile_a)
{
	if (!*pile_b)
		return ;
	ft_pa_pb_min(pile_b, pile_a);
}

void	ft_pb(t_PILE **pile_a, t_PILE **pile_b)
{
	if (!*pile_a)
		return ;
	ft_pa_pb_min(pile_a, pile_b);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1)
		return (1);
	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
