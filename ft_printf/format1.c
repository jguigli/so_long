/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:15:53 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/21 14:15:55 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_c(va_list arg, int *count)
{
	char	c;
	char	*temp;

	c = va_arg(arg, int);
	if (!c)
		*count += 1;
	temp = malloc(sizeof(char) * 2);
	if (!temp)
		return (NULL);
	temp[0] = c;
	temp[1] = '\0';
	return (temp);
}

char	*format_s(va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	if (s == NULL)
	{
		s = malloc(sizeof(char) * 7);
		if (!s)
			return (NULL);
		s[0] = '(';
		s[1] = 'n';
		s[2] = 'u';
		s[3] = 'l';
		s[4] = 'l';
		s[5] = ')';
		s[6] = '\0';
		return (s);
	}
	s = ft_strdup(s);
	return (s);
}

char	*format_p(va_list arg)
{
	unsigned long long int	p;
	char					*adress;
	char					*temp;

	p = (unsigned long long int)va_arg(arg, void *);
	temp = ft_itoa_ui(p, "0123456789abcdef");
	adress = ft_strdup("0x");
	adress = ft_strjoin(adress, temp);
	free(temp);
	return (adress);
}

char	*format_d(va_list arg)
{
	int	d;

	d = va_arg(arg, int);
	return (ft_itoa_base(d, "0123456789"));
}
