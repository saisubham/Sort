#include "sort.h"

void sort (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
