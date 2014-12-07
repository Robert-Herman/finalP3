#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

float seriesSum(float N);

int main(void)
{
    float macheps = 1.;
    while ((float)(1.+macheps) != 1)
    {
        macheps /= 2;
    }
    printf("macheps = %5.20f\n", macheps);
    float baseSum = (pow(M_PI,4))/90.0;
    printf("baseSum = %20.15f\n", baseSum);
    float N = 10.0;
    float relError = macheps*3.0;
    float error = 1;
    while (error > relError)
    {
    	float calcSum = seriesSum(N);
    	error = fabs(calcSum-baseSum);
    	printf("Sum = %5.15f for N = %5.0f Error = %5.15f\n", calcSum, N, error);
    	N = N *2;
    }    
}

float seriesSum(float N)
{
	float k;
	float sum = 0.;
	for (float i = N; i >= 1; i--)
	{	
		k = i*i*i*i;
		sum += (1./k);
	}
    return sum;
}
