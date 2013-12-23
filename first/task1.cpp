#include "task1.h"

void task1(){

	int N;
	float f;
	
	printf("N = ");
	scanf("%i", &N);
	
	printf("f = ");
	scanf("%f", &f);
	
	double result = 1;
	
	for(int i = 1; i <= N; i++){
		
		float tmp = 0;
		
		for(int k = 0; k <= i; k++){
			tmp += f + k;
		}
		
		result *= 1/tmp;
		
	}
	
	printf("result = %f\n", result);
}
