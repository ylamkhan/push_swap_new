/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:32:52 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/06 03:35:17 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_stock(int i, const char *str, int d)
{
	int	stock;

	stock = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		stock = stock * 10 + str[i] - 48;
		if (stock * d < INT32_MIN || stock * d > INT32_MAX)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (d * stock);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	stock;
	int	d;

	i = 0;
	stock = 0;
	d = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		d = (-1) * d;
		i++;
	}
	else if (str[i] == '+')
		i++;
	stock = ft_stock(i, str, d);
	return (stock);
}

int	ft_lstsize1(t_PILE *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_stock_pile_a(int ac, char **av, t_PILE **pile_a)
{
	char	**arg;
	int		i;
	int		j;
	int		stock;
	t_PILE	*new;

	i = 1;
	while (i < ac)
	{
		arg = ft_split(av[i], ' ');
		j = 0;
		while (arg[j])
		{
			stock = ft_atoi(arg[j]);
			if (stock != 0)
			{
				new = ft_lstnew(stock);
				ft_lstadd_back(pile_a, new);
			}
			j++;
		}
		i++;
	}
	return (0);
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
