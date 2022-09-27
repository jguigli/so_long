/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:36:34 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/14 18:39:34 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
char	*ft_itoa_base(int nb, char *base);
char	*ft_itoa_ui(unsigned long long int nb, char *base);
char	*format_c(va_list arg, int *count);
char	*format_s(va_list arg);
char	*format_p(va_list arg);
char	*format_d(va_list arg);
char	*format_i(va_list arg);
char	*format_u(va_list arg);
char	*format_x(va_list arg);
char	*format_upperx(va_list arg);
char	*format_percent(void);
char	*read_format(const char *format, va_list arg, int *count);
char	*read_format2(const char *format, va_list arg, char *str, int *count);
char	*read_format3(char format, char *temp, int *count, char *str);
char	*check_format(char iformat, va_list arg, int *count);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa_ui(unsigned long long int nb, char *base);
char	*ft_itoa_base(int nb, char *base);
char	*ft_strjoin_c_null(char *s1, char *s2);

#endif