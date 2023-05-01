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

//#define M_PI 3.1415926535
/*A = 0.3
*/

int main(int argc, char **argv){ 
    int A = atoi(argv[1]);
    int n = atoi(argv[2]);                    
    short sample[n * 13200];            
    for (int j = 0; j < n; j++){
        for(int i = 0; i < 13200; i++){
            sample[i] = (short)(A * sin(2 * 3.1415926535 * j * 440 * pow(2,1/12) * i / 44100));    
        }
    }
    write(1, sample, 2 * n);
}