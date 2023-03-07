/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:20:34 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 17:31:24 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;
	unsigned int	j;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) - start <= len)
		len = ft_strlen((s + start));
	p = (char *)malloc(len * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (j < len && *(s + i + j))
	{
		*(p + j) = *(s + i + j);
		j++;
	}
	*(p + j) = '\0';
	return (p);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	len;
	int	a;

	i = 0;
	len = 0;
	a = 1;
	while (s[i])
	{
		if (s[i] != c && a)
		{
			a = 0;
			len++;
		}
		if (s[i] == c)
			a = 1;
		i++;
	}
	return (len);
}

static int	ft_lencount(char const *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[*i])
	{
		if (s[*i] == c)
		{
			break ;
		}
		(*i)++;
		len++;
	}
	return (len);
}

static void	*freemove(char ***ptr, int d)
{
	int		i;
	char	**a;

	a = *ptr;
	i = 0;
	if (!a[d])
	{
		while (d >= 0)
		{
			free(a[d]);
			d--;
		}
		free(a);
		return (0);
	}
	return ((void *)1);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		d;
	char	**ptr;

	i = 0;
	d = 0;
	if (!s)
		return (NULL);
	ptr = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		ptr[d] = ft_substr(s, i, ft_lencount(s, c, &i));
		if (!freemove(&ptr, d))
			return (NULL);
		d++;
	}
	ptr[d] = NULL;
	return (ptr);
}
