/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:52:51 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/06 03:31:26 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	printferror(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int	ft_checker_min(t_PILE **pile_a, t_PILE **pile_b, char *str)
{
	if (!ft_strncmp(str, "sa", 2))
		ft_sa_sb(pile_a);
	else if (!ft_strncmp(str, "sb", 2))
		ft_sa_sb(pile_b);
	else if (!ft_strncmp(str, "ss", 2))
		ft_ss(pile_a, pile_a);
	else if (!ft_strncmp(str, "ra", 2))
		ft_ra_rb(pile_a);
	else if (!ft_strncmp(str, "rb", 2))
		ft_ra_rb(pile_b);
	else if (!ft_strncmp(str, "rra", 3))
		ft_rra_rrb(pile_a);
	else if (!ft_strncmp(str, "rrb", 3))
		ft_rra_rrb(pile_b);
	else if (!ft_strncmp(str, "rr", 2))
		ft_rr(pile_a, pile_b);
	else if (!ft_strncmp(str, "rrr", 3))
		ft_rrr(pile_b, pile_a);
	else if (!ft_strncmp(str, "pa", 2))
		ft_pa(pile_b, pile_a);
	else if (!ft_strncmp(str, "pb", 2))
		ft_pb(pile_a, pile_b);
	else
		printferror();
	return (1);
}

void	ft_checker(t_PILE **pile_a, t_PILE **pile_b)
{
	int		i;
	char	*str;

	i = 1;
	while (i)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		i = ft_checker_min(pile_a, pile_b, str);
		free(str);
	}
	if (ft_check_pile_sort(pile_a) && !ft_lstsize1(*pile_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
