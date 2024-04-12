#include <stdio.h>
#include <unistd.h> 

int	print_formatted(int num, char x, int chars)
{

}

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
