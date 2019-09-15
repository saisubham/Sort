#include "sort.h"

char *choices[] = {
		"Bubble sort",
		"Selection sort",
		"Insertion sort",
		"Merge sort",
		"Quick sort",
		"Exit"
};
int n_choices = sizeof(choices)/sizeof(char*);

void executeAlgo(int choice) {
	clear();
	
	int n;
	printw("Enter number of elements: ");
	scanw("%d", &n);

	int a[n];

	printw("Enter %d elements:\n", n);
	for (int i = 0; i < n; ++i)
		scanw("%d", &a[i]);

	timeout(TIME_OUT);

	switch(choice) {
		case 1: bubbleSort(a, n);
				break;
		case 2: selectionSort(a, n);
				break;
		case 3: insertionSort(a, n);
				break;
		case 4: mergeSort(a, n, 0, n - 1);
				break;
		case 5: quickSort(a, n, 0, n - 1);
				break;
		default: return;
	}
}

void printMenu(WINDOW* win, int highlight) {
	int x = 2, y = 2;
	
	box(win, 0, 0);
	
	for(int i = 0; i < n_choices; ++i) {
		if(highlight == i + 1) {
			wattron(win, A_REVERSE);
			mvwprintw(win, y, x, "%s", choices[i]);
			wattroff(win, A_REVERSE);
		}
		else
			mvwprintw(win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(win);
}

void createMenu() {
	WINDOW* menu_win;
	int c, row, col, startx, starty;		//screen data
	int highlight = 1, choice = 0, height, width;	//menu data
	height = 2 * n_choices;
	width = 30;

	initscr();
	clear();
	noecho();
	cbreak();
	
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	
	getmaxyx (stdscr, row, col);
	
	starty = (col - height) / 2;
	startx = (row - width) / 2;
	
	menu_win = newwin(height, width, startx, starty);
	keypad(menu_win, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down. Please Enter to select a choice");
	refresh();
	printMenu(menu_win, highlight);

	for(;;) {
		c = wgetch(menu_win);
		switch(c) {
			case KEY_UP: if(highlight == 1)
					     highlight = n_choices;
				     else
					     --highlight;
				     break;
			case KEY_DOWN: if(highlight == n_choices)
					       highlight = 1;
				       else
					       ++highlight;
				       break;
			case 10: choice = highlight;
				 break;
			default: mvprintw(2, 0, "Charcter pressed is %c", c);
				 refresh();
				 break;
		}
		printMenu(menu_win, highlight);
		if(choice != 0) {	/* User did a choice come out of the infinite loop */
			executeAlgo(choice);
			break;
		}
	}

	clrtoeol();
	refresh();
	endwin();
	return;
}