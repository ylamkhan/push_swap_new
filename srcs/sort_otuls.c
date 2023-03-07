/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_otuls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:24:50 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 03:03:55 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_is_sort(t_PILE *pile)
{
	while (pile->next)
	{
		if (pile->num > pile->next->num)
			return (0);
		pile = pile->next;
	}
	return (1);
}

void	pos_min_max(t_PILE **pile, int *min, int *max)
{
	int		t[2];
	t_PILE	*tmp;

	tmp = *pile;
	*max = tmp->num;
	*min = tmp->num;
	t[0] = 1;
	t[1] = 1;
	ft_index(*pile);
	while (tmp)
	{
		if (*max < tmp->num)
		{
			*max = tmp->num;
			t[0] = tmp->index + 1;
		}
		if (*min > tmp->num)
		{
			*min = tmp->num;
			t[1] = tmp->index + 1;
		}
		tmp = tmp->next;
	}
	*max = t[0];
	*min = t[1];
}

void	ft_index(t_PILE *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		pile->index = i;
		pile = pile->next;
		i++;
	}
}

int	get_index_min(t_PILE **pile)
{
	t_PILE	*tmp;
	int		min;
	int		index_min;

	ft_index(*pile);
	tmp = *pile;
	min = tmp->num;
	index_min = 0;
	while (tmp)
	{
		if (min > tmp->num)
		{
			min = tmp->num;
			index_min = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index_min);
}
