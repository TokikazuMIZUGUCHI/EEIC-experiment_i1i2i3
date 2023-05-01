#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<math.h>


/*量子化ビット数： 16bit
チャンネル数 １
標本の符号化方式 signed-int
標本化周波数： 44100 Hz*/



int main(int argc, char **argv){ 
    int A = atoi(argv[1]);
    int n = atoi(argv[3]);                  
    int f = atoi(argv[2]);    
    short sample[n];            

    for(int i = 0; i < n; i++){
        sample[i] = (short)(A * sin(2 * 3.1415926535 * f * i / 44100));    
    }
    write(1, sample, 2 * n);
}
