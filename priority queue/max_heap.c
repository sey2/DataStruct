#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
	char work[MAX_ELEMENT];
	int priority;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;


void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i = ++(h->heap_size);

	while ((i != 1) && (item.priority > h->heap[i / 2].priority)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
	element tmp, item;

	item = h->heap[1];
	tmp = h->heap[(h->heap_size)--];

	int parent = 1, child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && ((h->heap[child].priority) < (h->heap[child + 1].priority)))
			child++;
		if (tmp.priority < h->heap[child].priority) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = tmp;
	return item;

}

int main(void) {
	element m = { 0,0 };
	char ch;

	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	init(h);

	do {
		printf("삽입(i), 삭제(d): "); scanf("%c", &ch);
		switch (ch) {
		case 'i':
			getchar();
			printf("할일 :"); scanf_s("%[^\n]s", m.work, MAX_ELEMENT);
			printf("우선순위 :"); scanf("%d", &m.priority); getchar();
			insert_max_heap(h, m);
			break;
		case 'd':
			m = delete_max_heap(h);
			printf("우선 순위가 높은 일은 %s\n", m.work); getchar();
			break;
		default:
			break;
		}
	} while (h->heap_size != 0);

	return 0;
}
