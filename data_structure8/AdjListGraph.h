#pragma once
#define MAX_V 30 //정점의 최대 개수

typedef struct _GraphNode { //인접리스트 노드 그래프
	int data;
	struct _GraphNode *next; //정점과 연결된 노드에 대한 포인터
}GraphNode;

typedef struct _AdjListNode { //인접리스트 그래프 구조체
	int n; //정점의 개수
	int visited[MAX_V]; //정점 방문여부 표시
	GraphNode *hp[MAX_V]; //각 정점의 헤드포인터 배열
} AdjListGraph;

typedef AdjListGraph Graph;
