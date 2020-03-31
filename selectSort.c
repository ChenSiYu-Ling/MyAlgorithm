#include "sort.h"

#define N 10

void sort(int a[], int n);

int main(int argc, char *argv[])
{
	int a[N];
	
	init(a, N);
	sort(a, N);
	show(a, N);
	
	return 0;
} 

void sort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (less(a[j], a[min]))
				min = j;
		}
		exch(a, i, min);
	}
}
