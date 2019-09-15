#include "sort.h"

void selectionSort (int a[], int n) {
	for (int i = 0; i < n; ++i) {
		int min_pos = i;
		for (int j = i + 1; j < n; ++j) {

			printState(stdscr, a, n, j, min_pos);
			checkUserResponse();

			if (a[j] < a[min_pos])
				min_pos = j;

			printState(stdscr, a, n, j, min_pos);
			checkUserResponse();
		}
		swap (&a[i], &a[min_pos]);
	}
	printState(stdscr, a, n, j, min_pos);
	checkUserResponse();
}
