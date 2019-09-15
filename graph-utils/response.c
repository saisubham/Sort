#include "sort.h"

void checkUserResponse() {
	int ch = getch();

	switch(ch) {
		case KEY_F(1): 
					endwin();
					exit(0);
		case KEY_UP: 
					TIME_OUT -= 100;
					timeout(TIME_OUT);
					break;
		case KEY_DOWN: 
					TIME_OUT += 100;
					timeout(TIME_OUT);
					break;
		default:
					return;
	}
}