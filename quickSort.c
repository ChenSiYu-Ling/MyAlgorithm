#include "sort.h"

#define N 10

void sort(int a[], int lo, int hi);
int partition(int a[], int lo, int hi);

int main(void)
{
    int a[N];

    init(a, N);
    sort(a, 0, N - 1);
    show(a, N);

    return 0;
}

void sort(int a[], int lo, int hi)
{
    if (hi <= lo)
        return;
    int j = partition(a, lo, hi);
    sort(a, lo, j - 1);
    sort(a, j + 1, hi);
}

int partition(int a[], int lo, int hi)
{
    int i = lo, j = hi + 1;
    int v = a[lo];
    while (true)
    {
        while (less(a[++i], v));
        while (less(v, a[--j]));

        if (i >= j)
            break;
        exch(a, i, j);
    }

    exch(a, lo, j);
    return j;
}