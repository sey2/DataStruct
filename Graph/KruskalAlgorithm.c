#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES]; /// �θ���

void set_init(int n) {
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}


/// curr�� ���ϴ� ������ ��ȯ�Ѵ�.
int set_find(int curr) {
	if (parent[curr] == -1)
		return curr;	/// ��Ʈ
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}

/// �ΰ��� ���Ұ� ���� ������ ��ȯ�Ѵ�.
void set_union(int a, int b) {

	int root1 = set_find(a);	/// ��� a�� ��Ʈ�� ã�´�.
	int root2 = set_find(b);	/// ��� b�� ��Ʈ�� ã�´�.

	if (root1 != root2)		/// ���Ѵ�.
		parent[root1] = root2;
}

struct Edge {	/// ������ ��Ÿ���� ����ü
	int start, end, weight; 
};

typedef struct GraphType {
	int n;
	struct Edge edges[2 * MAX_VERTICCES];  /// ������ �� -> 2e
}GraphType;

void graph_init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICCES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = 0;
	}
}

void insert_edge(GraphType* g, int start, int end. int w) {
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

/// qsort()�� ���Ǵ� �Լ�
int compare(const void* a, const void* b) {
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

void kruskal(GraphType* g) {
	int edge_accepted = 0;
	int uset, vset;
	struct Edge e;

	set_init(g->n);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	printf("ũ�罺Į �ּ� ���� Ʈ�� �˰�����\n");
	int i = 0;
	while (edge_accepted < (g->n - 1))	/// ������ �� < (n-1)
	{
		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);

		if (uset != vset) {	    /// ���� ���� ������ �ٸ��ٸ�
			printf("���� (%d,%d) %d���� \n", e.start, e.end, e, weight);
			edge_accepted++;
			set_union(uset, vset);		/// �ΰ��� ������ ��ģ��
		}
		i++;
	}
}

int main(void) {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);

}