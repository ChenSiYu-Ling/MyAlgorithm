#include "sort.h"

#define N 10

static int aux[N];

void sort(int a[], int lo, int hi);
void merage(int a[], int lo, int mid, int hi);

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
    
    int mid = lo + (hi - lo) / 2;
    sort(a, lo, mid);
    sort(a, mid + 1, hi);
    merage(a, lo, mid, hi);
}

void merage(int a[], int lo, int mid, int hi)
{
    int i = lo, j = mid + 1;

    for (int k = lo; k <= hi; k++)
        aux[k] = a[k];
    
    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        else if (less(aux[j], aux[i]))
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
}
