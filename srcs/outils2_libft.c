/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2_libft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:28:43 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/06 01:04:16 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	ft_stock(int i, const char *str, int d)
{
	int	stock;

	stock = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		if ((stock * 10 + str[i] - 48) < stock)
		{
			if (d == 1)
				return (-1);
			else
				return (0);
		}
		stock = stock * 10 + str[i] - 48;
		i++;
	}
	return (d * stock);
}

int	ft_atoi(char *str)
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

char	*ft_strdup(char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
