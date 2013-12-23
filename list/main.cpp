#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data {
	char key[50];
	char value[50];
	struct data *next;
};

void print(struct data *beg, struct data *end){
	puts ( "Содержимое списка: " );
	struct data *curr=NULL;
	curr=beg;
	while ( curr != NULL) {
		printf( " %s = %s\n", curr->key, curr->value);
		curr = curr->next;
	}
}

void get(struct data *beg, struct data *end, char key[50]){
	printf("Ищем %s\n", key);
	struct data *curr=NULL;
	curr=beg;
	while ( curr != NULL) {
		if(strcmp(curr->key, key) == 0){
			printf( " %s = %s\n", curr->key, curr->value);
		}
		curr = curr->next;
	}
}

void remove(struct data **beg, struct data **end, char key[50]){
	printf("Удаляем %s\n", key);
	struct data *curr = NULL;
	struct data *prev = NULL;
	curr=*beg;
	while ( curr != NULL) {
		if(strcmp(curr->key, key) == 0){

			if(*beg == curr){
				prev=NULL;
				free(curr);
				curr = (*beg)->next;
				*beg = curr;
			} else {
				prev=*beg; //поиск предыдущего эл-та
				while( (prev->next) != curr){
					prev = prev->next;
				}
				prev->next = curr->next;
				free(curr);
				curr = prev->next;
			}
		} else {
			curr = curr->next;
		}
	}
}

void put(struct data **beg, struct data **end, char key[50], char value[50]){
	struct data *curr = (struct data *) malloc(sizeof (struct data));
	strcpy(curr->key, key);
	strcpy(curr->value, value);
	
	//список пуст
	if ( *beg == NULL && *end == NULL){
		*beg = curr; //включить звено в новый список
	} else {
		(*end)->next = curr; //включить звено в список
	}
	(*end) = curr;
	(*end)->next = NULL;
}

void update(struct data **beg, struct data **end, char key[50], char value[50]){
	printf("Обновляем %s = %s\n", key, value);
	struct data *curr=NULL;
	curr=*beg;
	while ( curr != NULL) {
		if(strcmp(curr->key, key) == 0){
			strcpy(curr->value, value);
		}
		curr = curr->next;
	}
}

main(){
	struct data *beg=NULL; //указатель на начало списка
	struct data *end=NULL; //указатель на конец списка
	
	put(&beg, &end, "name", "Ivan");
	put(&beg, &end, "name1", "Mike");
	put(&beg, &end, "name2", "Bob");
	
	print(beg, end);
	get(beg, end, "name2");
	print(beg, end);
	remove(&beg, &end, "name2");
	print(beg, end);
}
