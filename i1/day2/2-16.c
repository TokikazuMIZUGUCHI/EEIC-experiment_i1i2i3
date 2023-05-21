#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#define _POSIX_SOURCE

int main(int argc, char ** argv){
    if (argc != 3){
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    float pi = 3.1415926535;
    int A = atoi(argv[1]);
    int n = atoi(argv[2]);
    short signal[13230 * n];
    float t = 1.0 / 44100;
    float f = 440;
    f *= pow(2, 1.0/6);
    for (int i = 0; i < 13230 * n; i++){
        signal[i] = (short)(A * sin(2 * pi * f * t * i));
        if (i % 13230 == 0){
            switch ((i / 13230) % 7){
            case 1:
            f *= pow(2, 1.0 / 6);
            break;
            case 2:
            f *= pow(2, 1.0 / 6);
            break;
            case 3:
            f *= pow(2, 1.0 / 12);
            break;
            case 4:
            f *= pow(2, 1.0 / 6);
            break;
            case 5:
            f *= pow(2, 1.0 / 6);
            break;
            case 6:
            f *= pow(2, 1.0 / 6);
            break;
            case 0:
            f *= pow(2, 1.0 / 12);
            break;
            default:
            break;
        }
        }

    }
    short fd = open("doremi.raw", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, signal, 2 * n * 13230);
}