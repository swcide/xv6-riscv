#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int n = 50000;
  char buf = 'p';

  int a[2];
  int b[2];
  pipe(a);
  pipe(b);

  int pid = fork();

  if (pid == 0) {
    for (int i = 0; i < n; i++) {
      read(a[0], &buf, 1);
      write(b[1], &buf, 1);
    }
    exit(0);
  } else {
    int t = uptime();
    for (int i = 0; i < n; i++) {
      write(a[1], &buf, 1);
      read(b[0], &buf, 1);
    }
    t = uptime() - t;
    if (t == 0) t = 1;

    printf("%d\n", n * 100 / t);
    wait(0);
    exit(0);
  }
}
