#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[14];
int arr2[14];
int k;
void DFS(int Start, int Depth)
{
    int i;
    if (Depth == 6)
    {
        for (i = 0; i < 6; i++)
        {
            printf("%d ", arr2[i]);
        }
        printf("\n");
    }
    else
    {
        for (i = Start; i < k; i++)
        {
            arr2[Depth] = arr[i];
            DFS(i + 1, Depth + 1);
        }

    }
}

int main()
{
    int i;
    while (1) {
        scanf("%d", &k);
        if (k == 0)
            break;
            for (i = 0; i < k; i++)
                scanf("%d", &arr[i]);
        DFS(0, 0);
        printf("\n");
    }
}