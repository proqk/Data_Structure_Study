#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayStack.h"

int b_index = 0;
char b[100];

//중위표현식에서 후위표현식으로
void IntoPost(char a[], char b[]) {
	Stack cal;
	Init(&cal);
	b_index = 0;

	for (int i = 0; i < strlen(a); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[b_index++] = a[i]; //숫자는 바로 후위배열에 저장
		}
		else { //숫자가 아니면 연산자

			   //여는 괄호는 무조건 스택에 넣음
			if (a[i] == '(') {
				Push(&cal, a[i]);
			}

			else if (a[i] == ')') { //닫는 괄호 만나면 여는 괄호까지 pop
				while (Peek(&cal) != '(') { //여는 괄호까지
					b[b_index++] = Peek(&cal); //후위배열에 저장하고
					Pop(&cal); //팝
				}
				Pop(&cal); //'('없앰
			}

			//우선순위가 a[i]보다 높거나 같은 것들을 pop
			//곱셈과 나눗셈보다 우선순위가 높은 것은 없음
			else if (a[i] == '*' || a[i] == '/') {
				while (!isEmpty(&cal) && (Peek(&cal) == '*' || Peek(&cal) == '/')) {
					b[b_index++] = Peek(&cal);
					Pop(&cal);
				}
				Push(&cal, a[i]);
			}

			else { //더하기 빼기인 경우
				while (!isEmpty(&cal) && Peek(&cal) != '(') {
					//우선순위가 a[i]보다 높거나 같은 것들 pop할껀데
					//더하기 빼기가 제일 우선순위가 낮으므로 '('나 스택이 빌 때까지 pop
					b[b_index++] = Peek(&cal);
					Pop(&cal);
				}
				Push(&cal, a[i]);
			}
		}
	}
	//스택에 남은 것들 전부 pop
	while (!isEmpty(&cal)) {
		b[b_index++] = Peek(&cal);
		Pop(&cal);
	}
//	printf("postfix : %s, ", b);
	printf("postfix: ");
	for (int i = 0; i < b_index; i++) {
		printf("%c", b[i]);
	}
	puts("");
}

//후위표현식 문자열 내용을 읽어 계산하고 결과 출력
int PostCalculator(char b[]) {
	Stack s;
	Init(&s);
	int l, r;

	for (int i = 0; i < strlen(b); i++) {
		if (b[i] >= '0' && b[i] <= '9') {
			Push(&s, b[i] - '0'); //정수로 만들어서 스택에 저장
//			Display(&s);
		}
		else { //연산자라면
			r = Peek(&s);
			Pop(&s);
			l = Peek(&s);
			Pop(&s);
//			printf(">%d %d\n", r, r - l);

			switch (b[i]) {
				case '+':
					Push(&s, r + l); break;
				case '-':
					Push(&s, l - r); break;
				case '*':
					Push(&s, r * l); break;
				case '/':
					Push(&s, l / r); break;
			}
		}
//		Display(&s);
	}
	return Peek(&s);
}

int main() {
	char exp[100][100] = { "3*2-5", "7+3*4-2", "2+(3-6)*3" };
	char b[100];
	//char exp1[] = "3*2-5";
	//char exp2[] = "7+3*4-2";
	//char exp3[] = "2+(3-6)*3";

	//for (int i = 0; i < 3; i++) {
	//	printf("infix : %s\n", exp[i]);
	//	IntoPost(exp[i], b);
	//	printf(" , %d\n\n", PostCalculator(b));
	//}
//	printf("%d\n\n", PostCalculator("236-3*+"));
	//printf("infix : ");
	//scanf("%s", a);
	//IntoPost();
	printf("%d\n%d\n%d", PostCalculator("32*5-"), PostCalculator("734*+2-"), PostCalculator("236-3*+"));
}
