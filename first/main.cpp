#include <stdio.h>
#include "task1.h"
#include "task2.h"

int main() {

	char ch;

	while(true){	
		printf("Введите номер задачи [1-6]:\n");
		
		do{
			ch = getchar();
		}while(ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6');
		
		switch(ch){
			case '1':
				task1();
				break;
			case '2':
				task2();
				break;	
			case '0':
				return 0;
				break;
		}		
	}
	
	return 0;
}
