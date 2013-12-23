#include <stdlib.h>
#include <stdio.h>
#include <string.h>

main(){
	FILE *fp;
	
	fp = fopen("file.txt", "r");
	if(!fp){
		printf("File not found\n");
		exit(1);
	}
	
	float number;
	float* numbers = new float[100];
	int total = 0;
	float middle = 0;
	int count = 0;
	
	while(fscanf(fp, "%f", &number) != -1){
		numbers[total] = number;
		middle += number;
		total++;
	}
	
	middle = (float)middle/total;
	
	for(int i = 0; i < total; i++){
		printf("a[%i] = %.2f\n", i, numbers[i]);
		if(numbers[i] < middle){
			count++;
		}
	}
	
	printf("Среднее арифметическое = %f\n", middle);
	printf("Всего значекний %i\n", count);
	
	fclose(fp);
}
