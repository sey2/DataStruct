#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

#define KEY_SIZE 11
#define TABLE_SIZE 11

typedef int element;

element hash[TABLE_SIZE];


void init_table(element ht[]) {
	int i;

	for (i = 0; i < TABLE_SIZE; i++)
		ht[i] = 0;
}

int hash_function(int key) {
	return key % TABLE_SIZE;
}

void hash_lp_add(int item, element ht[]) {
	int i, hash_value;
	hash_value = i = hash_function(item);

	while (ht[i] != 0) {
		if (item == ht[i]) {
			fprintf(stderr, "탐색키가 중복 되었습니다.\n"); return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득 찼습니다.\n"); return;
		}
	}
	ht[i] = item;
}

void hash_lp_search(int item, element ht[]) {
	int i, hash_value;
	hash_value = i = hash_function(item);
	while (ht[i] != 0) {
		if (item == ht[i]) {
			fprintf(stderr, "찾은 값:%d 위치 = %d\n", item, i); return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "찾는 값이 테이블에 없음\n");
		}
	}

	fprintf(stderr, "찾는 값이 테이블에 없음\n");
}

void hash_lp_print(element ht[]) {
	int i;
	printf("\n=============================================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("인덱스: [%d] -> %d\n", i, ht[i]);
	printf("=============================================\n");
	
}

void hash_qp_add(int item, element ht[]) {
	int i, hash_value, inc = 0;
	i = hash_value = hash_function(item);
	while (ht[i] != 0) {
		if (item == ht[i]) {
			fprintf(stderr, "탐색키가 중복 되었습니다."); return;
		}
		i = (hash_value + inc * inc) % TABLE_SIZE;
		inc = inc + 1;
	}
	ht[i] = item;
	
}

int main(void) {
	int a[KEY_SIZE] = { 12, 44,13,88,23,94,11,39,20,16,5 };
	for (int i = 0; i < 11; i++) {
		hash_qp_add(a[i], hash);
		hash_lp_print(hash);
	}
}