/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:56:03 by vnicoles          #+#    #+#             */
/*   Updated: 2024/05/07 16:44:18 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int	count_digits(int num)
{
	int	count;
	int	copy;

	copy = num;
	count = 0;
	if (copy < 0)
		count++;
	if (copy == 0)
		return (1);
	while (copy != 0)
	{
		copy /= 10;
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

int	count_chars(char* buffer)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (buffer[i])
	{
		count++;
		i++;
	}
	return (count);
}

int	get_hex(unsigned int num, char x, char* buffer)
{
	int		remainder;
	char	hex_digit;

	if (num != 0)
	{
		remainder = num % 16;
		if (remainder <= 9)
			hex_digit = remainder + '0';
		else if (x == 'X')
			hex_digit = remainder + 55;
		else
			hex_digit = remainder + 87;
		*buffer++ = hex_digit;
	}
	return (buffer);
}

int	convert_to_hex(va_list args, char x, int alt_form, int field_width,
						unsigned int left_or_0pad,
						unsigned int plus_or_space)
{
	unsigned int	num;
	unsigned int	written_chars;
	char			buffer[9];
	char			*hex;
	int				len;

	written_chars = 0;
	num = va_arg(args, unsigned int);
	len = count_chars(get_hex(num, x, buffer));


	# TODO: FINISH THIS!!!!
	if (left_or_0pad == 1)
		return (print_left_aligned_int(num, field_width, 0, len));
	else if ((left_or_0pad == 2) && (field_width > 0))
		return (print_0padded_int(num, field_width, plus_or_space, len));
	if (((plus_or_space == 1) || (plus_or_space == 2)) && (num >= 0))
		len++;
	while (field_width > len)
	{
		ft_putchar_fd(' ', 1);
		field_width--;
		chars++;
	}
	if ((plus_or_space == 1) && (num >= 0))
		ft_putchar_fd('+', 1);
	else if ((plus_or_space == 2) && (num >= 0))
		ft_putchar_fd(' ', 1);
	ft_putnbr_fd(num, 1);
	field_width -= len;
	chars += len;
	return (chars);
	
	

	if (num == 0)
	{
		ft_putnbr_fd('0', 1);
		return (1);
	}
	return (get_hex(num, x, written_chars, buffer));
}

int print_left_aligned_int(int num, int field_width,
							unsigned int plus_or_space, unsigned int len)
{
	unsigned int	chars;

	chars = 0;
	if ((plus_or_space == 1) && (num >= 0))
	{
		ft_putchar_fd('+', 1);
		len++;
	}
	else if ((plus_or_space == 2) && (num >= 0))
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	ft_putnbr_fd(num, 1);
	field_width -= (len);
	chars += (len);
	while (field_width > 0)
	{
		ft_putchar_fd(' ', 1);
		field_width--;
		chars++;
	}
	return (chars);
}


int print_0padded_int(int num, int field_width,
						unsigned int plus_or_space,
						unsigned int len)
{
	unsigned int	chars;

	chars = 0;
	if ((plus_or_space == 1) && (num >= 0))
	{
		ft_putchar_fd('+', 1);
		len++;
	}
	else if ((plus_or_space == 2) && (num >= 0))
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	ft_putnbr_fd(num, 1);
	field_width -= len;
	chars += len;
	while (field_width > 0)
	{
		ft_putchar_fd('0', 1);
		field_width--;
		chars++;
	}
	return (chars);
}

int	parse_formatted_int(int num, int field_width,
						unsigned int left_or_0pad,
						unsigned int plus_or_space)
{
	unsigned int	len;
	unsigned int	chars;

	chars = 0;
	len = count_digits(num);
	if (left_or_0pad == 1)
		return (print_left_aligned_int(num, field_width, plus_or_space, len));
	else if ((left_or_0pad == 2) && (field_width > 0))
		return (print_0padded_int(num, field_width, plus_or_space, len));
	if (((plus_or_space == 1) || (plus_or_space == 2)) && (num >= 0))
		len++;
	while (field_width > len)
	{
		ft_putchar_fd(' ', 1);
		field_width--;
		chars++;
	}
	if ((plus_or_space == 1) && (num >= 0))
		ft_putchar_fd('+', 1);
	else if ((plus_or_space == 2) && (num >= 0))
		ft_putchar_fd(' ', 1);
	ft_putnbr_fd(num, 1);
	field_width -= len;
	chars += len;
	return (chars);
}

int	parse_fl_pnt(int num, int fl_pnt_prec, int field_width,
					unsigned int plus_or_space)
{
	unsigned int	len;
	unsigned int	chars;

	chars = 0;
	len = count_digits(num);
	if (((plus_or_space == 1) || (plus_or_space == 2)) && (num >= 0))
		chars++;
	while ((field_width > fl_pnt_prec) && (fl_pnt_prec > len))
	{
		ft_putchar_fd(' ', 1);
		field_width--;
		chars++;
	}
	if ((plus_or_space == 1) && (num >= 0))
		ft_putchar_fd('+', 1);
	else if ((plus_or_space == 2) && (num >= 0))
		ft_putchar_fd(' ', 1);
	while (fl_pnt_prec > len)
	{
		ft_putchar_fd('0', 1);
		fl_pnt_prec--;
		chars++;
	}
	ft_putnbr_fd(num, 1);
	field_width -= len;
	chars += len;
	return (chars);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	chars;
	unsigned int	left_or_0pad;
	unsigned int	alt_form;
	unsigned int	i;
	unsigned int	plus_or_space;
	unsigned int	field_width;
	int				fl_pnt_prec;
	int				to_print;
	int				num;
	char*			num_str;

	fl_pnt_prec = 0;
	i = 0;
	chars = 0;
	plus_or_space = 0;
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
					left_or_0pad = 1;
				if (*format == '0')
				{
					if (left_or_0pad == 1)
						left_or_0pad = 1;
					else
						left_or_0pad = 2;
				}
				if (*format == '+')
					plus_or_space = 1;
				if (*format == ' ')
				{
					if (plus_or_space == 1)
						plus_or_space = 1;
					else
						plus_or_space = 2;
				}
				if (*format == '#')
					alt_form = 1;
				format++;
			}
			field_width = 0;
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
					fl_pnt_prec = fl_pnt_prec * 10
						+ (*format - '0');
					format++;
				}
				num = va_arg(args, int);
				chars += parse_fl_pnt(num, fl_pnt_prec,
						field_width, plus_or_space);
				format++;
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
				chars += parse_formatted_int(num, field_width,
						left_or_0pad, plus_or_space);
				format++;
			}
			else if (*format == 'u')
			{
				chars += print_unsigned_int(args);
				format++;
			}
			else if ((*format == 'x') || (*format == 'X'))
			{
				chars += convert_to_hex(args, *format, alt_form);
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
	printed_chars = ft_printf("Hello! I'm %.4i\n", age);
	ft_printf("That was %i characters", printed_chars);
	return (0);
}
