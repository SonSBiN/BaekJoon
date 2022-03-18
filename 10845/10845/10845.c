#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int queue[10001];
int n_front = 0;
int n_rear = 0;
int n_size = 0;

void push(int num) {
	queue[n_rear] = num;
	n_size++;
	n_rear++;
}

void pop() {
	if (n_size == 0) {
		printf("%d\n",-1);
		return;
	}
	else {
		printf("%d\n",queue[n_front]);
		n_front++;
		n_size--;
	}
}
void size() {
	printf("%d\n", n_size);
}

void empty() {
	if (n_size == 0) {
		printf("%d\n",1);
	}
	else {
		printf("%d\n",0);
	}
}

void front() {
	if (n_size == 0) {
		printf("%d\n",-1);
		return;
	}
	else {
		printf("%d\n", queue[n_front]);
	}
}

void back() {
	if (n_size == 0) {
		printf("%d\n",-1);
		return;
	}
	else {
		printf("%d\n", queue[n_rear-1]);
	}
}


int main(void) {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char temp[10];
		scanf("%s", temp);
		if (!strcmp(temp, "push")) {
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if (!strcmp(temp, "pop")){
			pop();
		}
		else if (!strcmp(temp, "size")) {
			size();
		}
		else if (!strcmp(temp, "empty")) {
			empty();
		}
		else if (!strcmp(temp, "front")) {
			front();
		}
		else if (!strcmp(temp, "back")) {
			back();
		}
	}

	return 0;
}