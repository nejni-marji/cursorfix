#include "main.h"

/*
 * minecraft non-f11 center pos: x: 960, y: 536
 * minecraft yes-f11 center pos: x: 960, y: 540
 *
 * if we detect either of these, also reset relative
 */

int main(int argc, char** argv) {
	DC curs = DisplayCursor();
	int w, h;
	curs.getDisplaySize(w, h);
	int x, y, x2, y2, dx, dy;
	float dxp, dyp;
	bool isWiggled = false;
	// for (int i=0; i<60*20; i++) {
	while (true) {
		// old pos
		x2 = x;
		y2 = y;
		// new pos
		curs.getCursorPos(x, y);
		// delta
		dx = x-x2;
		dy = y-y2;
		// delta percent
		dxp = (float) abs(dx)/w;
		dyp = (float) abs(dy)/h;
		// check if movement has occurred (if so, reset isWiggled, and
		// optionally display debug info)
		if (dx!=0 || dy!=0) {
			// printf("w: %i, h: %i\n", w, h);
			// printf("x: %i, y: %i\n", x, y);
			// printf("dx: %i, dy: %i\n", dx, dy);
			// printf("dxp: %f, dyp: %f\n", dxp, dyp);
			// printf("%f\n", dxp);
			// printf("%f\n", dyp);
			isWiggled = false;
		}
		if (
				// do not wiggle unnecessarily
				(! isWiggled)
				&&
				(
					// if the cursor moved too fast
					(dxp > 0.25 || dyp > 0.25)
					||
					// if the cursor is at the center of the screen
					(x==960 && (y==540||y==536))
				)
		   ) {
			// wiggle the cursor
			curs.setCursorPos(1, 1);
			curs.setCursorPos(-1, -1);
			isWiggled = true;
		}
	}

	return 0;
}
