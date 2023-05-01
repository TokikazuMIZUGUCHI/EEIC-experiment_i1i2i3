#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open(argv[1], O_RDWR);
  if (fd == -1) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }

  int num = 0;
  int buf[1];
  for (;;) {
    if (read(fd, buf, 2)) {
      printf("%d %d\n", num, (short)buf[0]);
      num++;
    } else {
      break;
    }
  }

  return 0;
}