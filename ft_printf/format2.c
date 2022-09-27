/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:16:02 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/21 14:16:07 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_i(va_list arg)
{
	int	d;

	d = va_arg(arg, int);
	return (ft_itoa_base(d, "0123456789"));
}

char	*format_u(va_list arg)
{
	unsigned int	ui;

	ui = va_arg(arg, unsigned int);
	return (ft_itoa_ui(ui, "0123456789"));
}

char	*format_x(va_list arg)
{
	int	d;

	d = va_arg(arg, int);
	return (ft_itoa_base(d, "0123456789abcdef"));
}

char	*format_upperx(va_list arg)
{
	int	d;

	d = va_arg(arg, int);
	return (ft_itoa_base(d, "0123456789ABCDEF"));
}

char	*format_percent(void)
{
	char	*temp;

	temp = malloc(sizeof(char) * 2);
	if (!temp)
		return (NULL);
	temp[0] = '%';
	temp[1] = '\0';
	return (temp);
}
