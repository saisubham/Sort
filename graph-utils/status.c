#include "sort.h"

void printState (WINDOW* win, int a[], int n, int color1, int color2) {
	clear();
	
	int row, col, min_h, base, max_h, startx;
	min_h = max_h = a[0];

	for (int i = 1; i < n; ++i) {
		if (a[i] < min_h)
			min_h = a[i];
		else if (a[i] > max_h)
			max_h = a[i];
	}

	getmaxyx (win, row, col);
	base = row + min_h - 1;
	startx = (col - n) / 2;

	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= abs(a[i]); ++j) {
			int sign = a[i] > 0 ? 1 : -1;
			
			if (i == color1 || i == color2) {
				attron (A_BOLD | COLOR_PAIR (i == color1 ? 1 : 2));
				mvprintw (base - j * sign, startx + i, "*");
				attroff (A_BOLD | COLOR_PAIR (i == color1 ? 1 : 2));
			}
			else
				mvprintw (base - j * sign, startx + i, "*");

		}
	wrefresh(win);
}
