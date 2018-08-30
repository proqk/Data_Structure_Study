#include <stdio.h>
int a[15],b[15],c[15], tmp, n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = c[i] = a[i];
	}
	printf("\n정렬전: ");
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n버블정렬\n");
	for (int i = 0; i < n; i++){ //전체 탐색

		for (int j = 0; j < n - (i + 1); j++){ //하나 지날 때마다 비교하는 횟수가 줄음
			if (a[j] > a[j + 1]){ //뒷에 수>앞에 수면 자리 바꿈
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
		for (int k = 0; k < n; k++){
			printf("%d ", a[k]);
		}
		printf("\n");
	}

	printf("\n\n선택정렬\n");
	for (int i = 0; i < n - 1; i++){ //하나를 찍음
		int min = i;
		for (int j = i + 1; j < n; j++){
			if (b[min] > b[j]) min = j; //찍은 값을 우측으로 비교해 가면서 더 작은 값 중에 제일 작은 값 찾기
		}
		tmp = b[min];
		b[min] = b[i];
		b[i] = tmp; //자리 바꿈

		for (int k = 0; k < n; k++){
			printf("%d ", b[k]);
		}
		printf("\n");
	}

	printf("\n\n삽입정렬\n");
	for (int i = 1; i < n; i++){
		int key = c[i], j = i - 1; //지금 찍은 숫자가 비교하는 숫자보다 크면 뒤로 보냄
		while (j >= 0 && c[j] > key){
			c[j + 1] = c[j];
			j--;
		}
		c[j + 1] = key;
		for (int k = 0; k < n; k++){
			printf("%d ", c[k]);
		}
		printf("\n");
	}
}
