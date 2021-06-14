#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n) {
	int least, temp;

	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (list[j] > list[i]) {
				SWAP(list[i], list[j], temp);
			}

		}
	}
}

int main(void) {
	int i;
	int n = MAX_SIZE;
	for (int i = 0; i < n; i++) 
		list[i] = rand() % 100;

	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n\n")

	selection_sort(list, n);

	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
}