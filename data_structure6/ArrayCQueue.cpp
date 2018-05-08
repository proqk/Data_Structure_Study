#include <stdio.h>
#include <stdlib.h>
#include "ArrayCQueue.h"

void Init(Queue *q){
	q->back = 0;
	q->front = 0;
}

int isEmpty(Queue *q){
	if (q->back == q->front) return 1; //둘이 만나면 비었음
	else return 0;
}

int Next(int nowback){
	//if (nowback == MAX - 1) return 0;
	//else return nowback + 1;

	return (nowback + 1) % MAX; //지금 back의 다음 값 반환
}

int isFull(Queue *q){
//	printf(">%d %d\n", (q->back+1) % 5, q->front);
	if (q->front == Next(q->back)) return 1; //앞이 뒤+1이면 꽉참
	else return 0;
}


void Enqueue(Queue *q, element item){
	if (isFull(q)) printf("삽입 포화\n");
	else{
		q->back = Next(q->back); // 뒤에 넣을 공간 만듬
		q->data[q->back] = item; //거기에 넣음
	}
}

element Dequeue(Queue *q){
	element del_item; // 삭제할 값을 담은 데이터 변수
	if (isEmpty(q)) {
		printf("삭제 공백\n");
		return -1;
	}
	else{
		del_item = q->front; //맨 앞을 삭제할꺼임
		q->front = Next(q->front); //원래 맨 앞 데이터가 있어도 없는 취급함
		return q->data[q->front]; //삭제하려는 값 반환
	}
}

element Peek(Queue *q){
	if (isEmpty(q)) {
		printf("픽 공백\n");
		return -1;
	}
	else{
		return q->data[q->front + 1]; //맨 앞의 값 반환
	}
}

void Display(Queue *q){
	if (isEmpty(q)) printf("출력 공백\n");
	else{
		printf("front [ ");
		
		for (int i = q->front +1 ; i <= q->back; i++){ //앞~뒤 사이 값 출력함
			printf("%d ", q->data[i]);
		}

		printf("] back\n\n");
	}
}

int main(){
	Queue q1;
	Init(&q1);

	for (int i = 1; i <= 5; i++){
		printf("Enqueue( %d )\n", i);
		Enqueue(&q1, i);
		Display(&q1);
	}

	printf("Peek : %d\n", Peek(&q1));
	Display(&q1);

	while (!isEmpty(&q1)){
		printf("\nDequeue: %d\n", Dequeue(&q1));
		Display(&q1);
	}
	puts("\n");
}
