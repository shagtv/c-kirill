#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data {
	char key[50];
	char value[50];
};

void print(char* fname){
	data curr;

	FILE *fp;
	fp = fopen(fname, "rb");

	while(fread(&curr, sizeof(data), 1, fp) > 0){
		printf("%s = %s\n", curr.key, curr.value);
	}

	fclose(fp);
}

void get(char* fname, char key[50]){
	data curr;

	FILE *fp;
	fp = fopen(fname, "rb");

	while(fread(&curr, sizeof(data), 1, fp) > 0){
		if(strcmp(curr.key, key) == 0){
			printf("%s = %s\n", curr.key, curr.value);
		}
	}

	fclose(fp);
}

void remove(char* fname, char key[50]){
	data curr, curr1;

	FILE *fp, *tmp;
	fp = fopen(fname, "r+b");
	tmp = fopen("tmp.data", "ab");

	while(fread(&curr, sizeof(struct data), 1, fp) > 0){
		if(strcmp(curr.key, key) != 0){
			fwrite(&curr, sizeof(data), 1, tmp);
		}
	}
	fclose(fp);
	fclose(tmp);
	rename("tmp.data", fname);
}

void put(char* fname, char key[50], char value[50]){
	struct data curr;
	strcpy(curr.key, key);
	strcpy(curr.value, value);

	FILE *fp;
	fp = fopen(fname, "ab");

	fwrite(&curr, sizeof(data), 1, fp);

	fclose(fp);
}

void update(char* fname, char key[50], char value[50]){
	data curr;

	FILE *fp;
	fp = fopen(fname, "r+b");

	while(fread(&curr, sizeof(data), 1, fp) > 0){
		if(strcmp(curr.key, key) == 0){
			strcpy(curr.value, value);
			long int position = ftell(fp);

			position -= sizeof(data);
			fseek(fp, position, SEEK_SET);

			fwrite(&curr, sizeof(data), 1, fp);
		}
	}

	fclose(fp);
}

main(){

	char *fname = "file.data";
	FILE *fp;
	fp = fopen(fname, "w");
	if(!fp){
		printf("file open error\n");
		exit(1);
	}
	fclose(fp);

	put(fname, "name", "Ivan");
	put(fname, "name1", "Mike");
	put(fname, "name2", "Bob");
	put(fname, "name3", "Rob");

	print(fname);

	printf("\n\n");

	remove(fname, "name2");

	printf("\n\n");

	print(fname);
}
