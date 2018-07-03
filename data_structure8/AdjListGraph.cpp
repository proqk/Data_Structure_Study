#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "AdjListGraph.h"
using namespace std;

//정점의 개수 0으로 초기화, 인접리스트 정점의 헤드포인터 배열 값 NULL로 초기화
void InitGraph(Graph *g){
	g->n = 0; //초기화
	for (int i = 0; i<MAX_V; i++) { //헤더포인터 초기화
		g->hp[i] = NULL;
	}
}

//허용된 정점의 수를 넘지 않는 범위에서 그래프의 정점생성
void InsertVertex(Graph *g, int v){
	if (v > MAX_V){
		printf("최대 정점 개수 초과");
		return;
	}
	g->n = v;
}

//그래프에 두 정점 v1 v2를 잇는 간선 삽입, v1의 헤드포인터에 v2를 data값으로 가지는 새로운 노드 생성하여 삽입
//v1, v2는 배열의 인덱스이므로(0~그래프정점수-1)의 범위 안, 무방향 그래프일 경우 동시에 v2의 헤드포인터에 v1을 데이터값으로 가지는 새로운 노드 생성 삽입
void InsertEdge(Graph *g, int v1, int v2){
	if (g->n <= v1 || g->n <= v2){ //두 정점 번호는 정점의 수보다 작아야 함, 그렇지 않다면 그래프에 없는 정점
		printf("\n그래프에 없는 정점임\n");
		return;
	}

	GraphNode *newnode = (GraphNode*)malloc(sizeof(GraphNode)); //새로운 그래프 노드 생성
	newnode->data = v2; //새 노드의 정점 데이터는 v2
	newnode->next = g->hp[v1]; //새 노드의 다음 노드는 정점 v1의 헤드포인터가 가리키던 노드
	g->hp[v1] = newnode; //정점 v1의 헤드포인터는 새로운 노드를 가리킴

	GraphNode *newnode2 = (GraphNode*)malloc(sizeof(GraphNode)); //무방향 그래프면 반대 방향으로도 간선 연결됨
	newnode2->data = v1;
	newnode2->next = g->hp[v2];
	g->hp[v2] = newnode2;
}

void DisplayGraph(Graph *g){ //그래프 내용 출력 - 각 정점의 헤드포인터에 연결된 노드 값을 모두 출력
	GraphNode *temp;
	for (int i = 0; i < g->n; i++){
		printf("정점 %c : ", i + 'A');
		for (temp = g->hp[i]; temp; temp=temp->next){
			printf("->%c ", temp->data + 'A');
		}
		printf("\n");
	}
}

void DFS(Graph *g, int v){
	GraphNode *temp;
	g->visited[v] = 1;
	printf("%c ", v + 'A');

	for (temp = g->hp[v]; temp; temp = temp->next){
		if (!g->visited[temp->data]){
			DFS(g, temp->data);
		}
	}
}

void BFS(Graph *g, int v){
	queue<int> q;
	GraphNode *temp;

	q.push(v);	
	g->visited[v] = 1;

	while (!q.empty()){
		v = q.front();
		q.pop();

		printf("%c ", v + 'A');
		for (temp = g->hp[v]; temp; temp = temp->next){
			if (!g->visited[temp->data]){
				q.push(temp->data);
				g->visited[temp->data] = 1;
			}
		}
	}
}

int main(){
	Graph g;
	InitGraph(&g);
	InsertVertex(&g, 7); //정점의 개수가 7개인 무방향 그래프
	//	printf(">>%d\n", g.n);
	InsertEdge(&g, 0, 2); //연결할 두 정점의 번호
	InsertEdge(&g, 0, 1);
	InsertEdge(&g, 1, 4);
	InsertEdge(&g, 1, 3);
	InsertEdge(&g, 3, 6);
	InsertEdge(&g, 4, 6);
	InsertEdge(&g, 5, 6);

	printf("g의 인접행렬 표현\n");
	DisplayGraph(&g);

	for (int i = 0; i < g.n; i++){
		g.visited[i] = 0; //방문기록 초기화
	}

	printf("\n\n깊이우선탐색결과\n");
	DFS(&g, 0);

	for (int i = 0; i < g.n; i++){
		g.visited[i] = 0; //방문기록 초기화
	}

	printf("\n\n너비우선탐색결과\n");
	BFS(&g, 0);
}
