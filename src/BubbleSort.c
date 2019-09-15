#include "sort.h"

void bubbleSort(int a[], int n) {
	for(int i=0;i<n;++i)
		for(int j=0;j<n-1;++j)
			if(a[j]>a[j+1]) {
				swap(&a[j],&a[j+1]);
				
				printState (stdscr, a, n, a[j + 1], a[j]);
				checkUserResponse();
			}
}
