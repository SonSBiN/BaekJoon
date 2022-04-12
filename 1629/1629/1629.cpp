#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int calculation(int A, int B, int C) {
	if (B <= 1)
		return A;
	else {
		long long result = calculation(A, B / 2, C);
		if (B % 2)
			return ((result * result) % C * A) % C;
		else
			return (result * result) % C;
	}
}

int main(void)
{
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", calculation(A%C, B, C));
	return 0;
}