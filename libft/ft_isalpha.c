#include <unistd.h>

int ft_isalpha(int a) {
  if (( a >= 'A' && a <= 'Z') || ( a >= 'a' && a <= 'z')) {
    return 1;
  } else {
    return 0;
  }
}
