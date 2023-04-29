#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define N  256

int main(){
    int fd = open("my_data.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    unsigned char data[N];
    for (int i = 0; i < N; i++){
        data[i] = i;
    }
    write(fd, data, N);
    close (fd);
    return 0;
}