#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    ssize_t readdd;
    unsigned char buff;
    int num = 0;
    while ((readdd = read(fd, &buff, 1)) > 0) {
        printf("%d %u\n", num, buff);
        num++;
    }

    if (readdd == -1) {
        perror("Error reading file");
        close(fd);
        exit(1);
    }

    close(fd);
    return 0;
}
