#include <stdio.h>
int count = 0;
int SequentialSearch(int A[], int n, int k){
	for (int i = 0; i < n; i++){ //0부터 끝까지 찾는다
		count++; //바로 찾아도 한 번 찾은거니까 일단 count부터 올려줌
		if (A[i] == k) { //찾으면
			return i; //index 반환
		}
	}
	return -1;
}
int main(){
	int A[] = { 5, 7, 12, 15, 20, 22, 25, 27, 30, 45 };
	int key, size = sizeof(A) / sizeof(int);

	printf("순차탐색 - 뭐 찾으실? ==> ");
	scanf("%d", &key);
	printf("%d의 위치: %d ", key, SequentialSearch(A, size, key));
	printf("\n\n비교횟수: %d", count);
}
