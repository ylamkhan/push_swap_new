/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:50:24 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/06 01:51:05 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		d;
	t_PILE	*pile_a;
	t_PILE	*pile_b;

	if (ac > 1)
	{
		pile_a = NULL;
		pile_b = NULL;
		d = ft_init(ac, av, &pile_a);
		if (d == 0)
			write(1, "error\n", 6);
		else
			ft_sort(&pile_a, &pile_b);
		return (0);
	}
	return (0);
	system("leaks push_swap");
}

int	ft_check_pile_sort(t_PILE **pile_a)
{
	t_PILE	*temp;

	temp = (*pile_a);
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_stock_pile_a1(int valeur, t_PILE **pile_a)
{
	t_PILE	*temp;
	t_PILE	*new;

	temp = (*pile_a);
	while (temp)
	{
		if (temp->num == valeur)
			return (0);
		temp = temp->next;
	}
	new = ft_lstnew(valeur);
	ft_lstadd_back(pile_a, new);
	return (1);
}

int	ft_is_not_digitl(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
