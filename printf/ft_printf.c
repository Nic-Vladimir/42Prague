/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:56:03 by vnicoles          #+#    #+#             */
/*   Updated: 2024/04/12 19:35:07 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int	count_digits(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	print_char(va_list args)
{
	char	character;

	character = va_arg(args, int);
	ft_putchar_fd(character, 1);
	return (1);
}

int	print_string(va_list args)
{
	char	*string;

	string = (va_arg(args, char *));
	ft_putstr_fd(string, 1);
	return (ft_strlen(string));
}

int	print_pointer(va_list args)
{
	void	*ptr;
	char	hex_str[20];
	int		len;

	ptr = va_arg(args, void *);
	len = sprintf(hex_str, "%p", ptr);
	ft_putstr_fd(hex_str, 1);
	return (len);
}

int	print_unsigned_int(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		ft_putnbr_fd(0, 1);
		return (0);
	}
	if (num < 1)
		return (-1);
	ft_putnbr_fd(num, 1);
	return (count_digits(num));
}

int	convert_to_hexadecimal(unsigned int num, char x, int written_chars)
{
	int		remainder;
	int		i;
	char	hex_digit;

	if (num != 0)
	{
		remainder = num % 16;
		written_chars += convert_to_hexadecimal(num / 16, x, written_chars);
		if (remainder <= 9)
			hex_digit = remainder + '0';
		else if (x == 'X')
			hex_digit = remainder + 55;
		else
			hex_digit = remainder + 87;
		ft_putchar_fd(hex_digit, 1);
		written_chars++;
	}
	return (written_chars);
}

int	print_hexadecimal(va_list args, char x)
{
	unsigned int	num;
	unsigned int	written_chars;

	written_chars = 0;
	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		ft_putnbr_fd('0', 1);
		return (1);
	}
	return (convert_to_hexadecimal(num, x, written_chars));
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	chars;
	unsigned int	left_align;
	unsigned int	pad_with_0;
	unsigned int	alternate_form;
	unsigned int	i;
	unsigned int	plus_sign;
	unsigned int	space_for_positives;
	unsigned int	field_width;
	int				floating_point_precision;
	int				to_print;
	int				num;
	char*			num_str;

	i = 0;
	chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			chars++;
			ft_putchar_fd(*format, 1);
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
				chars += print_char(args);
				format++;
			}
			else if (*format == 's')
			{
				chars += print_string(args);
				format++;
			}
			else if (*format == 'p')
			{
				chars += print_pointer(args);
				format++;
			}
			else if ((*format == 'd') || (*format == 'i'))
			{
				num = va_arg(args, int);
				ft_putnbr_fd(num, 1);
				chars += count_digits(num);
				format++;
			}
			else if (*format == 'u')
			{
				chars += print_unsigned_int(args);
				format++;
			}
			else if ((*format == 'x') || (*format == 'X'))
			{
				chars += print_hexadecimal(args, *format);
				format++;
			}
			else if (*format == '%')
			{
				ft_putchar_fd('%', 1);
				chars += 1;
				format++;
			}
		}
	}
	va_end(args);
	return (chars);
}

int	main(void)
{
	int				printed_chars;
	unsigned int	age;
	char			*point;

	age = 24;
	printed_chars = ft_printf("Hello! My name is %c, and you are %s. I am %u years old and you are %p !\n*BANG* Here's a number for you, smarty-pants: %X\n", 'X', "stupid", age, point, 987);
	ft_printf("That was %d characters", printed_chars);
	return (0);
}
