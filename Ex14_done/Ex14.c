#include <stdio.h>
#include <time.h>
#define ASIZE 1000
int main()
{
    double data[ASIZE][ASIZE];
    clock_t start, stop;
    start = clock();
    for(int row = 0; row < ASIZE; row++)
    {
        for(int col = 0; col < ASIZE; col++)
        {
            data[row][col] = 0;
        }
    }
    for (int i = 0; i<ASIZE; i++) {
        for (int row = 0; row<ASIZE; row++) {
            for (int col = 0; col<ASIZE; col++) {
                data[row][col] += (double)(row+1)/(col+1)/(i+1);
                printf("%lf", data[row][col]);
                //                  System.out.println(data[row][col]);
            }
        }
    }
    stop = clock();
    double secondsDuration = (stop - start)/CLOCKS_PER_SEC;
    printf("Duration on seconds %f", secondsDuration);
    printf("\n");
    return 0;
}
