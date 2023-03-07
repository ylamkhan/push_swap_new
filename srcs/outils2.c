/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:52:03 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 22:12:34 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_max(t_PILE **pile)
{
	t_PILE	*tmp;
	int		max;
	int		index_min;

	ft_index(*pile);
	tmp = *pile;
	max = tmp->num;
	index_min = 0;
	while (tmp)
	{
		if (max < tmp->num)
		{
			max = tmp->num;
			index_min = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index_min);
}

void	pos_max_1(t_PILE **pile, int pos_min)
{
	if (pos_min == 2)
		ft_ra_rb(pile, 'a');
	else
	{
		ft_ra_rb(pile, 'a');
		ft_sa_sb(pile, 'a');
	}
}

void	pos_max_2(t_PILE **pile, int pos_min)
{
	if (pos_min == 1)
	{
		ft_sa_sb(pile, 'a');
		ft_ra_rb(pile, 'a');
	}
	else
		ft_rra_rrb(pile, 'a');
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
