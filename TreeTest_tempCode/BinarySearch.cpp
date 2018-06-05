#include <stdio.h>
int count;
int BinarySearch(int A[], int n, int k){

}
int main(){
	int A[] = { 5, 7, 12, 15, 20, 22, 25, 27, 30, 45 };
	int key, size = sizeof(A) / sizeof(int);

	printf("이진탐색 - 뭐 찾으실? ==> ");
	scanf("%d", &key);
	printf("%d의 위치: %d ", key, BinarySearch(A, size, key));
	printf("\n\n비교횟수: %d", count);
}
