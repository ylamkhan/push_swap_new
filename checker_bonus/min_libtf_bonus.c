/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_libtf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:16:43 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 17:29:20 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_lstadd_front(t_PILE **lst, t_PILE *new)
{
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
	{
		*lst = new;
		new->next = NULL;
	}
}

t_PILE	*ft_lstlast(t_PILE *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_PILE **lst, t_PILE *new)
{
	t_PILE	*last;

	last = ft_lstlast(*lst);
	if (!last)
	{
		*lst = new;
	}
	else
	{
		last->next = new;
	}
}

int	ft_lstsize(t_PILE *lst)
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

t_PILE	*ft_lstnew(int content)
{
	t_PILE	*neveau;

	neveau = malloc(sizeof(t_PILE));
	if (!neveau)
		return (NULL);
	neveau->num = content;
	neveau->next = NULL;
	return (neveau);
}
