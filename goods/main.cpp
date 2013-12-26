#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data {
	int code;
	char title[50];
	int count;
	float price;
	struct data *next;
};

void put(struct data **beg, struct data **end, int code, char title[50], int count, float price) {
	struct data *curr = (struct data *) malloc(sizeof (struct data));
	curr->code = code;
	strcpy(curr->title, title);
	curr->count = count;
	curr->price = price;

	//список пуст
	if (*beg == NULL && *end == NULL) {
		*beg = curr; //включить звено в новый список
	} else {
		(*end)->next = curr; //включить звено в список
	}
	(*end) = curr;
	(*end)->next = NULL;
}

void get(struct data *beg, struct data *end, char key[50], char value[50]) {
	printf("Ищем %s\n", key);
	struct data *curr = NULL;
	curr = beg;
	while (curr != NULL) {
		bool found = false;
		if (key == "code") {
			int code = atoi(value);
			if (curr->code == code) {
				found = true;
			}
		} else if (key == "title") {
			if (strcmp(curr->title, value) == 0) {
				found = true;
			}
		} else if (key == "count") {
			int count = atoi(value);
			if (curr->count == count) {
				found = true;
			}
		} else if (key == "price") {
			float price = atof(value);
			if (curr->price == price) {
				found = true;
			}
		}
		if (found) {
			printf("%i\t%s\t%i\t%f\n", curr->code, curr->title, curr->count, curr->price);
		}
		curr = curr->next;
	}
}

void print(struct data *beg, struct data *end) {
	puts("Содержимое списка: ");
	struct data *curr = NULL;
	curr = beg;
	while (curr != NULL) {
		printf("%i\t%s\t%i\t%f\n", curr->code, curr->title, curr->count, curr->price);
		curr = curr->next;
	}
}

void sort(struct data **beg, struct data **end) {

	bool run = true;
	data* cur;
	data* next;
	data* endsort = NULL;
	while (run) {
		cur = *beg;
		next = cur->next;
		run = false;
		while (next != endsort) {
			if ((cur->code) > (next->code)) {
				cur->next = next->next;
				next->next = cur;
				run = true;
			}
			cur = next;
			next = next->next;
			print(*beg, *end);
		}
	}
	
}

data *sort(struct data *beg) {
	data *q, *out = NULL, *p, *pr; //out - выход - сначала пуст
	while (beg != NULL) { //пока не конец входного списка
		q = beg;
		beg = beg->next; //исключить очередной элемент
		for (p = out, pr = NULL; p != NULL && (q->code > p->code); pr = p, p = p->next);
		//ищем, куда включить очередной элемент - тут strcmp
		//задает критерий сравнения элементов, в вашей задаче м.б. другой
		if (pr == NULL) {
			q->next = out;
			out = q;
		}//включение в начало
		else {
			q->next = p;
			pr->next = q;
		} //или после предыдущего
	}
	return out;
}

int main() {

	struct data *beg = NULL; //указатель на начало списка
	struct data *end = NULL; //указатель на конец списка

	FILE *fp;

	fp = fopen("goods.csv", "r");

	int code;
	char title[50];
	int count;
	float price;

	while (fscanf(fp, "%i\t%s\t%i\t%f\n", &code, title, &count, &price) > 0) {
		put(&beg, &end, code, title, count, price);
	}

	print(beg, end);

	//get(beg, end, "title", "LG");

	beg = sort(beg);
	
	print(beg, end);
	
	fclose(fp);
	return 0;
}