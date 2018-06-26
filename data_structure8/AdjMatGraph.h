#pragma once
#define MAX_V 30

//인접행렬 그래프
typedef struct _AdjMatrixGraph {
	int v_num; //정점의 개수
	int visited[MAX_V]; //정점 방문여부 표시
	int map[MAX_V][MAX_V]; //adjmatrix 간선 정보가 있는 인접행렬
} AdjMatrixGraph;

typedef AdjMatrixGraph Graph;
