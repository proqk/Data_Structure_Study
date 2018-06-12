#include <stdio.h>
#include <algorithm>
int cnt;
int BinarySearch(int a[], int n, int k){
	std::sort(a, a + n); //오름차순 정렬
	int l = 0, r = n - 1;
	while (l <= r){ //l이랑 r이랑 같아질 때까지
		int m = (l + r) / 2;
		cnt++;
//		printf(">%d\n", a[m]);
		if (k == a[m]) return m; //찾으면 리턴
		if (k < a[m]) r = m - 1; //찾으려는 데이터가 중간 값보다 작으면 오른쪽 범위를 줄여줌
		else l = m + 1; //중간 값보다 크면 왼쪽 범위를 줄여줌. 이 때 m값도 필요 없으니까 제외함
	}
	return -1; //못 찾으면 -1
}
int main(){
	int A[] = { 5, 7, 12, 15, 20, 22, 25, 27, 30, 45 };
	int key, size = sizeof(A) / sizeof(int);

	printf("이진탐색 - 뭐 찾으실? ==> ");
	scanf("%d", &key);
	printf("%d의 위치: %d ", key, BinarySearch(A, size, key));
	printf("\n\n비교횟수: %d", cnt);
}
