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
			fprintf(stderr, "Ž��Ű�� �ߺ� �Ǿ����ϴ�.\n"); return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "���̺��� ���� á���ϴ�.\n"); return;
		}
	}
	ht[i] = item;
}

void hash_lp_search(int item, element ht[]) {
	int i, hash_value;
	hash_value = i = hash_function(item);
	while (ht[i] != 0) {
		if (item == ht[i]) {
			fprintf(stderr, "ã�� ��:%d ��ġ = %d\n", item, i); return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "ã�� ���� ���̺� ����\n");
		}
	}

	fprintf(stderr, "ã�� ���� ���̺� ����\n");
}

void hash_lp_print(element ht[]) {
	int i;
	printf("\n=============================================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("�ε���: [%d] -> %d\n", i, ht[i]);
	printf("=============================================\n");
	
}

void hash_qp_add(int item, element ht[]) {
	int i, hash_value, inc = 0;
	i = hash_value = hash_function(item);
	while (ht[i] != 0) {
		if (item == ht[i]) {
			fprintf(stderr, "Ž��Ű�� �ߺ� �Ǿ����ϴ�."); return;
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