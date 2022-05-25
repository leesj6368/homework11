#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
#define TRUE 1
#define FALSE 0


typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;	// 정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;


void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void graph_init(GraphType* g);
void insert_vertex(GraphType* g, int v);
void insert_edge(GraphType* g, int u, int v);
void error(char* message);
void dfs_list(GraphType* g, int v);

void graph_init(GraphType* g) // 그래프 초기화 
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v) // 정점 삽입 연산
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
void insert_edge(GraphType* g, int u, int v) // 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}
int visited[MAX_VERTICES];

/*///////////////////////////////////////////////////////*/





void dfs_list(GraphType* g, int v) {
	GraphNode* w;
	visited[v] = TRUE;
	printf("%d ", v);
	for (w = g->adj_list[v]; w; w = w->link)// 인접 정점 탐색 
		if (!visited[w->vertex])
			dfs_list(g, w->vertex); //정점 w에서 DFS 새로시작
}
//
int main()
{

	GraphType *g = NULL;
	int u,v;
	char command;
	int key;
	printf("[----- [leeseonjue] [2021041042] -----]");
	do {
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf(                      "Graph Searches \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph = z                                      \n");
		printf(" Insert Vertex = v             Insert Edge = e              \n");
		printf(" Depth First Search = d        Breath First Search = b \n");
		printf(" Print Graph = p              Quit = q \n");
		printf("----------------------------------------------------------------\n");
		printf("Command = ");
		scanf(" %c", &command);
		switch (command) {
		case 'z': case 'Z':
			break;
		case 'v': case 'V':
			break;
		case 'e': case 'E':
            break;
		case 'd': case 'D':
            break;
		case 'b': case 'B':
            break;
		case 'p': case 'P':
            break;
        }
    }while(command != 'q' && command != 'Q');
return 1;
}	