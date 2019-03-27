#include <stdio.h>
#include <time.h>

#define ASIZE	1000

int main(void)
{
    double *ptr_data;
	double data [ASIZE][ASIZE];
    ptr_data = &data[0][0];
    
    int i, row, col;

    clock_t start = clock();
    for (row = 0; row<ASIZE; row++) {
        for (col = 0; col<ASIZE; col++) {
            data[row][col] = 0;
        }
    }

    for (i = 0; i<ASIZE; i++) {
        for (row = 0; row<ASIZE; row++) {
            for (col = 0; col<ASIZE; col++) {
                data[row][col] += (double)(row+1)/(col+1)/(i+1);
                printf("%lf\n", *(ptr_data + col + (ASIZE * row)));
            }
        }
    }

    clock_t stop = clock();
    double seconds_duration = (((double)stop - start) / CLOCKS_PER_SEC);
    printf("Duration in seconds: %lf\n", seconds_duration);

	return 0;
}
