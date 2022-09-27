/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:47:25 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/21 18:47:27 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_case_rep(int nb, unsigned int length)
{
	int				count;
	unsigned int	nbun;

	if (nb < 0 && length != 16)
	{
		count = 2;
		nbun = -nb;
	}
	else
	{
		count = 1;
		nbun = nb;
	}
	while (nbun >= length)
	{
		nbun /= length;
		count++;
	}
	return (count);
}

static int	count_case_rep_ui(unsigned long long int nb, unsigned int length)
{
	int	count;

	count = 1;
	while (nb >= length)
	{
		nb /= length;
		count++;
	}
	return (count);
}

char	*ft_itoa_ui(unsigned long long int nb, char *base)
{
	int				count;
	char			*rep;
	unsigned int	length;

	length = ft_strlen(base);
	count = count_case_rep_ui(nb, length);
	rep = (char *)malloc(sizeof(char) * (count + 1));
	if (!rep)
		return (NULL);
	rep[count] = '\0';
	while (nb >= length)
	{
		rep[--count] = base[nb % length];
		nb /= length;
	}
	rep[--count] = base[nb % length];
	return (rep);
}

char	*ft_itoa_base(int nb, char *base)
{
	int				count;
	unsigned int	length;
	char			*rep;
	unsigned int	val;

	length = ft_strlen(base);
	count = count_case_rep(nb, length);
	rep = (char *)malloc(sizeof(char) * (count + 1));
	if (!rep)
		return (NULL);
	if (nb < 0 && length != 16)
	{
		val = -nb;
		rep[0] = '-';
	}
	else
		val = nb;
	rep[count] = '\0';
	while (val >= length)
	{
		rep[--count] = base[val % length];
		val /= length;
	}
	rep[--count] = base[val % length];
	return (rep);
}
