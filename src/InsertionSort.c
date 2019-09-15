#include "sort.h"

void insertionSort(int a[], int n){
	for(int i = 1; i < n; ++i) {
		int x = a[i], j = i - 1;
		while(j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			--j;
			
			printState(stdscr, a, n, j, i);
			checkUserResponse();
		}
		a[j + 1] = x;

		printState(stdscr, a, n, j + 1, i);
		checkUserResponse();
	}
}
