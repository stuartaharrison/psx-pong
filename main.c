/* Pong Ultimate
 * 
 * main.c
 * Created by: S. Harrison
 * Date: 15-09-2018
 */

#include "constants.h"
#include "pong.h"

Ball ball;
int batOffset = 20;
Scoreboard scoreboard;
Bat batLeft, batRight;


int main() {
	initialize();

	while(1) {
		update();
		draw();
		display();
	}
	
	return 0;
}


void initialize() {
	initializeScreen();
	initializePad();
	
	// define the background colour
	setBackgroundColor(createColor(50, 50, 50));
	
	// define the 'playing field'
	
	// define the bat objects
	batLeft = createBat(batOffset);
	batRight = createBat(SCREEN_WIDTH - batOffset);
	
	// define the ball
	ball = createBall();
	
	// define the scoreboard
}


void update() {
	padUpdate();
}


void draw() {
	// draw the 'playing field'

	// draw the 'bat' objects
	drawBat(batLeft);
	drawBat(batRight);
	
	// draw the 'ball' object
	drawBall(ball);
	
	// draw the scoreboard
}
