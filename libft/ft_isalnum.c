#include <unistd.h>

int ft_isalnum(int a) {
  if (( a >= '0' && a <= '9' ) ||
    ( a >= 'A' && a <= 'Z' ) ||
    ( a >= 'a' && a <= 'z' )) {
    return 1;
  } else {
    return 0;
  }
}
