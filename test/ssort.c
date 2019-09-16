#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

int TIME_OUT = 500;

void printState (WINDOW* win, int a[], int n, int color1, int color2);
void check_usr_response();

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void selectionSort (int a[], int n) {
	int i, j, min_pos;
	for (i = 0; i < n; ++i) {
		min_pos = i;
		for (j = i + 1; j < n; ++j) {
			printState(stdscr, a,  n, j, min_pos);
			if (a[j] < a[min_pos])
				min_pos = j;
			printState(stdscr, a, n, j, min_pos);
			check_usr_response();
		}
		swap (&a[i], &a[min_pos]);
	}
	printState(stdscr, a, n, j, min_pos);
}

void printState (WINDOW* win, int a[], int n, int color1, int color2) {
        clear();
        int row, col, min_h, base, max_h, startx;
        min_h = max_h = a[0];

	printw("Use up/down arrow keys to speed up/slow down");

        for (int i = 1; i < n; ++i) {
                if (a[i] < min_h)
                        min_h = a[i];
                if (a[i] > max_h)
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
        refresh();
}

void check_usr_response()
{       int ch;
        ch = getch();
        if(ch == ERR)
                return;
        else if(ch == KEY_F(1)) {
                        endwin();
                        exit(0);
	}
	else if(ch == KEY_UP) {
		TIME_OUT /= 2;
		timeout(TIME_OUT);
	}
	else if(ch == KEY_DOWN) {
		TIME_OUT *= 2;
		timeout(TIME_OUT);
	}

}

int main (int argc, char* argv[]) {

        initscr();
        clear();
        cbreak();

        start_color();
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        init_pair(2, COLOR_CYAN, COLOR_BLACK);

	curs_set(FALSE);
        keypad(stdscr, TRUE);

        int n;

        printw("Enter no. of elements: ");
        scanw("%d",&n);
	
        int a[n];
        printw("Enter %d elements\n", n);
        for(int i = 0; i < n; ++i)
                scanw("%d", &a[i]);

	timeout(TIME_OUT);
        selectionSort(a, n);

        getch();
        refresh();
        endwin();
        return 0;
}
