/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:56:03 by vnicoles          #+#    #+#             */
/*   Updated: 2024/04/06 20:23:29 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	chars;

	i = 0;
	chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (format[i] != '%')
		{
			chars++;
			ft_putchar(*format);
			format++;
		}
		else
		{
			format++;
			while (*format == '-' || *format == '0' || *format == '#'
				|| *format == ' ' || *format == '+')
			{
				if (*format == '-')
					left_align = 1;
				if (*format == '0')
					pad_with_0 = 1;
				if (*format == '#')
					alternate_form = 1;
				if (*format == '+')
					plus_sign = 1;
				if (*format == ' ')
					space_for_positives = 1;
				format++;
			}
			while (*format >= '0' && *format <= '9')
			{
				field_width = field_width * 10 + (*format - '0');
				format++;
			}
			if (*format == '.')
			{
				format++;
				while (*format >= '0' && *format <= '9')
				{
					floating_point_precision = floating_point_precision * 10
						+ (*format - '0');
					format++;
				}
			}
			if (*format == 'c')
				//PrintCharacter
			else if (*format == 's')
				//PrintString
			else if (*format == 'p')
				//PrintPointerInHexadecimal
			if (*format == 'd')
				//PrintDecimalNumber
			if (*format == 'i')
				//PrintIntegerInBase10
			if (*format == 'u')
				//PrintInsignedDecimalNumber
			if (*format == 'x')
				//PrintHexadecimalNumberLowercase
			if (*format == 'X')
				//PrintHexadecimalNumberUppercase
			if (*format == '%')
				//Print%
		}
	}
}
