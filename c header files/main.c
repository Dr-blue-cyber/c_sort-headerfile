#include <stdio.h>
#include<stdlib.h>

#include "intro_sort.h"
int main()
{
    int a[] = { 5, 7, -8, 9, 10, 4, -7, 0, -12, 1, 6, 2, 3, -4, -15, 12 };
    int n= sizeof(a) / sizeof(a[0]);
    int l =sizeof(a);
    // get the maximum depth
    // int maxdepth = log(n) * 2;

    // sort the array using introsort the algorithm
    // csort(a, l, l + n - 1, maxdepth);

    heapSort(a,16);

    
    // print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }

    return 0;
}