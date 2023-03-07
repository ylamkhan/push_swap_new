/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:51:25 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 14:32:47 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_valeur_index(t_PILE *pile, int index)
{
	while (pile->next)
	{
		if (index == pile->index)
			return (pile->num);
		pile = pile->next;
	}
	return (0);
}

static void	min_ft_push_to_b(t_PILE **pile_a, t_PILE **pile_b, int T[6],
		int *tab)
{
	while (*pile_a)
	{
		if ((*pile_a)->num <= tab[T[4] - 1])
		{
			ft_pb(pile_a, pile_b);
			if (tab[(T[4] - (T[3] / 2)) - 1] >= (*pile_b)->num)
				ft_ra_rb(pile_b, 'b');
			(T[1])++;
		}
		else
			ft_ra_rb(pile_a, 'a');
		if (T[1] + (T[2] % T[5]) == T[2])
		{
			T[4] = T[2];
			T[0] = 0;
		}
		if (T[1] == T[3] * T[0])
		{
			(T[0])++;
			T[4] = T[3] * T[0];
		}
	}
	free(tab);
}

void	ft_push_to_b(t_PILE **pile_a, t_PILE **pile_b, int n)
{
	int		*tab;
	int		t[6];

	t[0] = 1;
	t[1] = 0;
	t[2] = ft_lstsize(*pile_a);
	tab = remplire_tab(pile_a, t[2]);
	t[3] = t[2] / n;
	if (t[3] == 1)
		t[3] = t[2];
	t[4] = t[3] * t[0];
	t[5] = n;
	min_ft_push_to_b(pile_a, pile_b, t, tab);
}
