#include "sort.h" 

void swap (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int a[], int l, int h) {
	int p = a[h], i = l - 1;

	for (int j = l; j < h; ++j) {
		if (a[j] <= p) {
			++i;
			swap (&a[i], &a[j]);
		}
	}

	swap (&a[i + 1], &a[h]);
	return i + 1;
}

void quickSort (int a[], int n, int l, int h) {
	if (l < h) {
		int p = partition (a, l, h);
		quickSort (a, l, p - 1);

		printState(stdscr, a, n, a[l], a[p - 1]);
		sleep(1);

		quickSort (a, p + 1, h);

		printState(stdscr, a, n, a[p+1], a[h]);
		sleep(1);
	}
}
