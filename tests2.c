#include <unistd.h>

int	main(void)
{
	int	chars = printf("Big hex is %20s\n", "Macarena");
	printf("Written chars: %d\n", chars);
	return (0);
}