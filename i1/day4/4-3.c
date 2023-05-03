#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int sample_rate = 44100;
    int frequency = 3528;
    int num_samples = sample_rate;
    double sin_wave[num_samples];
    double t;

    for (int i = 0; i < num_samples; i++) {
        t = (double)i / sample_rate;
        sin_wave[i] = sin(2 * 3.141592 * frequency * t);
    }

    FILE *fp = fopen("a.dat", "w");
    for (int i = 0; i < num_samples; i++) {
        t = (double)i / sample_rate;
        fprintf(fp, "%.6f %.6f\n", t, sin_wave[i]);
    }
    fclose(fp);

    return 0;
}
