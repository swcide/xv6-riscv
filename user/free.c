#include "kernel/types.h"
#include "user/user.h"

int main()
{
  uint64 bytes = freemem();
  printf("Free memory: %ld bytes\n", bytes);
  exit(0);
}
