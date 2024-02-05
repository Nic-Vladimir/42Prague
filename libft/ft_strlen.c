#include <unistd.h>

int ft_strlen(char *a) {
  int i;
  i = 0;
  while (*a != '\0') {
    i++;
    a++;
  }
  return i;
}
