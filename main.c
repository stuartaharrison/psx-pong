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
char scoreboard_text[100] = "";
Line lineTop, lineBottom, lineMiddle;

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
	// setup initalizers
	initializeScreen();
	initializePad();
	initializeDebugFont();
	
	// define the background colour
	setBackgroundColor(createColor(50, 50, 50));
	
	// define the 'playing field'
	lineTop = createLine(createColor(255, 255, 255), 0, 10, SCREEN_WIDTH, 10);
	lineBottom = createLine(createColor(255, 255, 255), 0, SCREEN_HEIGHT - 20, SCREEN_WIDTH, SCREEN_HEIGHT - 20);
	lineMiddle = createLine(createColor(150, 150, 150), SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
	
	// define the bat objects
	batLeft = createBat(batOffset);
	batRight = createBat(SCREEN_WIDTH - batOffset);
	
	// define the ball
	ball = createBall();
	
	// define the scoreboard
	scoreboard = createScoreboard();
}


void update() {
	// update based on controller input
	padUpdate();
	
	// check for Player 1 input
	if (padCheck(Pad1Up)) {
		batLeft = moveBat(batLeft, -2);
	}
	
	if (padCheck(Pad1Down)) {
		batLeft = moveBat(batLeft, 2);
	}
	
	// check for Player 2 input
	
	// dual input checks
	if (padCheck(Pad1Start) || padCheck(Pad2Start)) {
		ball = kickBall(ball);
	}
	
	// move the ball
	ball = moveBall(ball, batLeft, batRight);
	
	// update the scoreboard
	sprintf(scoreboard_text, "%d:%d", scoreboard.score_left, scoreboard.score_right);
}


void draw() {
	// draw the 'playing field'
	drawLine(lineTop);
	drawLine(lineBottom);
	drawLine(lineMiddle);
	
	// draw the 'bat' objects
	drawBat(batLeft);
	drawBat(batRight);
	
	// draw the 'ball' object
	drawBall(ball);
	
	// draw the scoreboard
	FntPrint(scoreboard_text);
}
