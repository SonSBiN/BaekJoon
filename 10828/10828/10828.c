#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int arr[10001];
int top_num = 0;
int top = -1;
int size;

void Stk_Push(int num) {
	arr[top_num] = num;
	top_num++;
	top++;
	return;
}

void Stk_Pop() {
	if (top == -1) {
		printf("%d\n", -1);
		return ;
	}
	top--;
	top_num--;
	printf("%d\n", arr[top + 1]);
	return;
}

void Stk_Size() {
	printf("%d\n", top_num);
	return;
}

void Stk_Empty() {
	if (top_num == 0) {
		printf("%d\n", 1);
		return;
	}
	else
		printf("%d\n", 0);
		return ;
}

void Stk_Top() {
	if (top == -1) {
		printf("%d\n", -1);
		return ;
	}
	else {
		printf("%d\n", arr[top]);
		return;
	}
}

int main(void) {
	size = 0;
	top_num = 0;
	int order_num;
    char order[10];
	 if (scanf("%d", &order_num) != 1) {
		 printf("명령의 수 입력 오류");
		 return 0;
	};
	for (int i = 0; i < order_num; i++) {
		if (scanf("%s", order) == 1) {
			if (!strcmp(order, "push")) {
				int push_num;
				scanf("%d", &push_num);
				Stk_Push(push_num);
			}
			else if (!strcmp(order, "pop")) {
				Stk_Pop();
			}
			else if (!strcmp(order, "size")) {
				Stk_Size();
			}
			else if (!strcmp(order, "empty")) {
				Stk_Empty();
			}
			else if (!strcmp(order, "top")) {
				Stk_Top();
			}
			else
				printf("명령어 입력 오류");
		}
	}
	return 0;
}