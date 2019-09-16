#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

int TIME_OUT = 500;

void printState (WINDOW* win, int a[], int n, int color1, int color2);
void check_usr_response();

void insertionSort(int a[], int n){
	for(int i = 1; i < n; ++i) {
		int x = a[i], j = i - 1;
		while(j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			--j;
			
			printState(stdscr, a, n, j, i);
			check_usr_response();
		}
		a[j + 1] = x;
		printState(stdscr, a, n, j + 1, i);
		check_usr_response();
	}
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

        for (int i = 0; i < n; ++i) {
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

        keypad(stdscr, TRUE);

        int n;

        printw("Enter no. of elements: ");
        scanw("%d",&n);

        int a[n];
        printw("Enter %d elements\n", n);
        for(int i = 0; i < n; ++i)
                scanw("%d", &a[i]);

	timeout(TIME_OUT);
        insertionSort(a, n);

        getch();
        refresh();
        endwin();
        return 0;
}
