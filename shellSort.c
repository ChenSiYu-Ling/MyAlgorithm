#include "sort.h"

#define N 10

void sort(int a[], int n);

int main(void)
{
    int a[N];

    init(a, N);
    sort(a, N);
    show(a, N);

    return 0;
}

void sort(int a[], int n)
{
    int h = 1;
    while (h < n / 3)
        h = h * 3 + 1;
    while (h >= 1)
    {
        for (int i = h; i < n; i++)
        {
            for (int j = i; j >= h && less(a[j], a[j - h]); j -= h)
                exch(a, j, j - h);
        }

        h = h / 3;
    }
}