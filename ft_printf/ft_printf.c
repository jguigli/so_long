/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:16:03 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/19 13:16:13 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_format(char iformat, va_list arg, int *count)
{
	char	*temp;

	temp = NULL;
	if (iformat == 'c')
		temp = format_c(arg, count);
	else if (iformat == 's')
		temp = format_s(arg);
	else if (iformat == 'p')
		temp = format_p(arg);
	else if (iformat == 'd')
		temp = format_d(arg);
	else if (iformat == 'i')
		temp = format_i(arg);
	else if (iformat == 'u')
		temp = format_u(arg);
	else if (iformat == 'x')
		temp = format_x(arg);
	else if (iformat == 'X')
		temp = format_upperx(arg);
	else if (iformat == '%')
		temp = format_percent();
	return (temp);
}

char	*read_format(const char *format, va_list arg, int *count)
{
	char	*str;

	str = ft_strdup("");
	str = read_format2(format, arg, str, count);
	return (str);
}

char	*read_format2(const char *format, va_list arg, char *str, int *count)
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	i = 0;
	while (format[i])
	{
		j = i;
		while (format[i] != '%' && format[i])
			i++;
		if (i != j)
		{
			temp = ft_substr(format, j, i - j);
			str = ft_strjoin(str, temp);
		}
		else if (format[i] == '%')
		{
			temp = check_format(format[i + 1], arg, count);
			str = read_format3(format[i + 1], temp, count, str);
			i += 2;
		}
		free(temp);
	}
	return (str);
}

char	*read_format3(char format, char *temp, int *count, char *str)
{
	if (format == 'c' && temp[0] == 0)
	{
		write(1, str, ft_strlen(str));
		*count += ft_strlen(str);
		free(str);
		write(1, &temp[0], 1);
		str = ft_strdup("");
	}
	else
		str = ft_strjoin(str, temp);
	return (str);
}

int	ft_printf(const char *format, ...)
{
	char	*str;
	va_list	arg;
	int		count;
	int		countplus;

	countplus = 0;
	va_start(arg, format);
	if (!format)
		return (-1);
	str = read_format(format, arg, &countplus);
	count = (int)ft_strlen(str);
	write(1, str, ft_strlen(str));
	free(str);
	va_end(arg);
	return (count + countplus);
}
