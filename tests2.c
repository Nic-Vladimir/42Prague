#include <unistd.h>

int	main(void)
{
	int	chars = printf("Big hex is %i\n", +21);
	printf("Written chars: %#030x\n", chars);
	return (0);
}