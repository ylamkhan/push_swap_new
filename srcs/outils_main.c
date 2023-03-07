/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:09:34 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/06 01:37:37 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_PILE **pile_a, t_PILE **pile_b)
{
	int	size;

	if (pile_is_sort(*pile_a))
		return ;
	size = ft_lstsize(*pile_a);
	if (size <= 2)
		sort_2(pile_a);
	else if (size == 3)
		sort_3(pile_a);
	else if (size <= 5)
		sort_4_5(pile_a, pile_b);
	else if (size <= 100)
		sort_100(pile_a, pile_b, 4);
	else
		sort_100(pile_a, pile_b, 10);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if ((str[i] == '+' || str[i] == '-') && !str[i + 1])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_is_not_digitl(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_2d_table(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

int	min_int(char **arg, t_PILE **pile_a)
{
	int	j;
	int	tmp;

	j = 0;
	while (arg[j])
	{
		if (!ft_check(arg[j]))
			return (0);
		else
		{
			tmp = ft_atoi(arg[j]);
			if ((tmp == -1 && ft_strncmp(arg[j], "-1", 2)) || (tmp == 0
					&& ft_strncmp(arg[j], "0", 1) && ft_strncmp(arg[j], "-0", 1)
					&& ft_strncmp(arg[j], "+0", 2)))
				return (0);
			if (!ft_stock_pile_a1(tmp, pile_a))
				return (0);
			j++;
		}
	}
	return (1);
}

int	ft_init(int ac, char **av, t_PILE **pile_a)
{
	char	**arg;
	int		i;

	i = 1;
	while (i < ac)
	{
		arg = ft_split(av[i++], ' ');
		if (!arg[0])
			return (0);
		if (!min_int(arg, pile_a))
			return (0);
		free_2d_table(arg);
	}
	return (1);
}
