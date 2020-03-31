#include "sort.h"

#include <stdio.h>

#define N 10

void sort(int a[], int n);

int main(void)
{
    int a[N];

    init(a, N);
    printf("排序前: ");
    show(a, N);

    printf("==============================================\n");
    sort(a, N);
    printf("排序后: ");
    show(a, N);

    return 0;
}

void sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && less(a[j], a[j - 1]); j--)
        {
            exch(a, j, j - 1);
        }
    }
}