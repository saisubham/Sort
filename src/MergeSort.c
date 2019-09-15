#include "sort.h"

void merge (int a[], int l, int m, int h) {
	int i, j, k, n1, n2;
	n1 = m - l + 1;
	n2 = h - m;
	int b[n1], c[n2];
	
	for (i = 0; i < n1; ++i)
		b[i] = a[l + i];
	for (j = 0; j < n2; ++j)
		c[j] = a[m + 1 + j];

	i = j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (b[i] <= c[j]) {
			a[k] = b[i];
			++i;
		}
		else {
			a[k] = c[j];
			++j;
		}
	}
	
	while (i < n1) {
		a[k] = b[i];
		++k;
		++i;
	}

	while (j < n2) {
		a[k] = c[j];
		++k;
		++j;
	}
}

void mergeSort (int a[], int n, int l, int h) {
	if (l < h) {
		int m = l + (h - l) / 2;
		mergeSort (a, l, m);

		printState(stdscr, a, n, a[l], a[m]);
		sleep(1);

		mergeSort (a, m + 1, h);

		printState(stdscr, a, n, a[m + 1], a[h]);
		sleep(1);

		merge (a, l, m, h);
	}
}
