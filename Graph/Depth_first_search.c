#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define TRUE 1
#define FALSE 0
int visited[MAX_VERTICES];
typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void init(GraphType* g)
{
	int v;
	int r, c;
	g->n = 0;

	for (r = 0; r < MAX_VERTICES; r++)
	{
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_list[r][c] = NULL;
	}
		

}

void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) {
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g -> n)
		return;

	g->adj_list[start][end] = 1;
	g->adj_list[end][start] = 1;
}

void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = TRUE;
	printf("정점 %d -> ", v);
	for (w = 0; w < g->n; w++) {
		if (g->adj_list[v][w] && !visited[w])	/// 연결된 정점이 있고, 방문하지 않았으면 w를 시작정점으로 깊이 우선탐색 시작
			dfs_mat(g, w);
	}
}

int main(void) {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	printf("깊이 우선 탐색\n");
	dfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0;
}