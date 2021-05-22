#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 8

int sorted[MAX_SIZE];
int list[MAX_SIZE] = { 27,10,12,20,25,13,15,22 };
int n;

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	/// 남은 레코드를 모두 sorted로 옮긴다.
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[j];
	}
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);	/// 전반부 정렬
		merge_sort(list, mid + 1, right);	/// 후반부 정렬
		merge(list, left, mid, right);	/// 합병
	}
}

int main(void) {
	int i;
	n = MAX_SIZE;;

	printf("--- 정렬전 ---\n");

	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	} printf("\n");

	merge_sort(list, 0, n-1);

	printf("\n--- 정렬후 ---\n");

	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

	printf("\n");
	return 0;
}