#include "sort.h"

#define N 1000

void sort(int a[], int lo, int hi);

int main(void)
{
    int a[N];

    init(a, N);
    sort(a, 0, N - 1);
    show(a, N);

    return 0;
}

// 从左到右遍历数组一次,
// 维护一个指针lt使得a[lo..lt - 1]中的元素都小于v,
// 一个指针gt使得a[gt + 1...hi]中的元素都大于v,
// 一个指针i使得a[lt..i - 1]中的元素都等于v,
// a[i...gt]中的元素都还未确定.
void sort(int a[], int lo, int hi)
{
    if (hi <= lo)
        return;
    int lt = lo, i = lo + 1, gt = hi;
    int v = a[lo];
    while (i <= gt)
    {
        // a[i]小于v,将a[lt]和a[i]交换,将lt和i加一;
        if (less(a[i], v))
            exch(a, lt++, i++);
        // a[i]大于v,将[gt]和a[i]交换,将gt减一;
        else if (!less(a[i], v))
            exch(a, i, gt--);
        else
        // a[i]等于v,将i加一.
            i++;

        // 上述操作都会保证数组元素不变且缩小gt - i的值(这样循环才能结束).
        // 另外,除非和切分元素相等,其他元素都会被交换.
    }
    sort(a, lo, lt - 1);
    sort(a, gt + 1, hi);
}