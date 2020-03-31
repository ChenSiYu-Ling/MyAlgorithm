#include "sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool less(int v, int w)
{
	return v < w;
}

void exch(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void show(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

void init(int a[], int n)
{
	srand((int)time(0));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
} 
