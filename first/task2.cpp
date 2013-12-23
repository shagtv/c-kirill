#include "task2.h"

void task2(){
	
	int day, month;
	int sum_day = 0, sum_month = 0, sum_year = 0;
	
	printf("day = ");
	scanf("%i", &day);
	
	printf("month = ");
	scanf("%i", &month);
	
	sum_day = day%10 + (day - day%10)/10;
	sum_month = month%10 + (month - month%10)/10;
	
	int year = 2013;
	
	do{
		year++;
		sum_year = year%10 + (year%100 - year%10)/10 + (year%1000 - year%100)/100 + (year%10000 - year%1000)/1000;
		printf("year = %i %i %i  %i\n", year, sum_day, sum_month, sum_year);
	} while(sum_year != sum_day && sum_year != sum_month);
	
	printf("year = %i\n", year);
	
}