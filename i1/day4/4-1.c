#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
    if(argc != 2) {
	fprintf(stderr, "usage: %s interval", argv[0]);
	exit(1);
    }

    int s = atoi(argv[1]);
    short ret;
    int i = 0;

    while(1) {
	int n = read(0, &ret, 2);
	if(n == -1) {exit(1);}
	if(n == 0) break;
	if(i % s == 0) write(1, &ret, 2);
	i++;
    }


    return 0;
}