#include <stdio.h>
#include <unistd.h> 

int	print_formatted_int(int num, int width_field,
						unsigned int left_align_or_0pad,
						unsigned int plus_sign_or_space)
{
	unsigned int	len;
	unsigned int	chars;

	chars = 0;
	len = count_digits(num);
	while (width_field > 0)
	{
		if (left_align_or_0pad == 2)
			ft_putchar_fd("0", 1);
		else if (left_align_or_0pad == 1)
		{
			ft_putnbr_fd(num, 1);
			width_field -= (len - 1);
			chars += (len - 1);
		}
		else
			ft_putchar_fd(" ", 1);
		width_field -= 1;
		chars++;
		if (width_field - len == 0)
		{
			ft_putnbr_fd(num, 1);
			width_field -= len;
			chars += len;
		}
	}
	return (chars);
}

int print_formatted_char(char x,)
{

}

int print_formatted_hexadecimal(int num, unsigned int alternate_form)


int	main(void)
{
	int		a;
	int		chars;
	int		written;

	a = 2;
	chars = 0;
	written = convert_to_hexadecimal(a, 'X', chars);
	printf("\nWritten %d characters\n", written);
	return (0);
}
