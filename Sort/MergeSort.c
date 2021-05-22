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
	/// ���� ���ڵ带 ��� sorted�� �ű��.
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
		merge_sort(list, left, mid);	/// ���ݺ� ����
		merge_sort(list, mid + 1, right);	/// �Ĺݺ� ����
		merge(list, left, mid, right);	/// �պ�
	}
}

int main(void) {
	int i;
	n = MAX_SIZE;;

	printf("--- ������ ---\n");

	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	} printf("\n");

	merge_sort(list, 0, n-1);

	printf("\n--- ������ ---\n");

	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

	printf("\n");
	return 0;
}