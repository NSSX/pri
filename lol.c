#include <stdio.h>
#include <string.h>


void
print_ptr(void *p)
{
  unsigned char t[sizeof p];
  size_t i;

  memcpy(t, &p, sizeof p);
  for (i = 0; i < sizeof p; ++i) {
    printf("%02x", t[i]);
  }
}


int
main(void)
{
  int n;
  int *p = &n;

  print_ptr(p);
  putchar('\n');
  return 0;
}
