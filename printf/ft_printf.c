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

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	chars;
    unsigned int    left_align;
    unsigned int    pad_with_0;
    unsigned int    alternate_form;
    unsigned int    i;
    unsigned int    plus_sign;
    unsigned int    space_for_positives;
    unsigned int    field_width;
    int             floating_point_precision;
    int             to_print;
    int             num;

	i = 0;
	chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			chars++;
			putchar(*format);
            //putchar('\n');
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
            {
			    to_print = va_arg(args, int);
                putchar(to_print);
                chars++;
                format++;
            }
            //else if (*format == 's')
			//	//PrintString
            //else if (*format == 'p')
			//	//PrintPointerInHexadecimal
            else if (*format == 'd')
			{
                num = va_arg(args, int);
                char num_str[12];
                snprintf(num_str, sizeof(num_str), "%d", num);
                int length = strlen(num_str);
                write(1, num_str, length);
                chars += length;
                format++;
            }
			//else if (*format == 'i')
			//	//PrintIntegerInBase10
			//else if (*format == 'u')
			//	//PrintInsignedDecimalNumber
			//else if (*format == 'x')
			//	//PrintHexadecimalNumberLowercase
			//else if (*format == 'X')
			//	//PrintHexadecimalNumberUppercase
			//else if (*format == '%')
			//	//Print%
		}
	}
    va_end(args);
    return (chars);
}

int main(void)
{
    int printed_chars;
    int age;

    age = 24;
    printed_chars = ft_printf("Hello! My name is %c, I am %d years old and you are terminated!\n*BANG*\n", 'X', age);
    ft_printf("That was %d characters", printed_chars);
    return (0);
}
