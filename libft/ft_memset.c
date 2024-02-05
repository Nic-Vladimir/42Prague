#include <unistd.h>

void *ft_memset(void *s, int c, size_t n) {
  unsigned char *p;
  unsigned char uc;

  *p = s;
  uc = c;
  while (n > 0) {
    *p++ = uc;
    n--;
  }
  return s;
}
