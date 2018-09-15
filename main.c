/* Pong Ultimate
 * 
 * main.c
 * Created by: S. Harrison
 * Date: 15-09-2018
 */

#include "constants.h"
#include "pong.h"

int main() {
	initialize();

	while(1) {
		update();
		draw();
		display();
	}
}

void initialize() {
	initializeScreen();
	initializePad();
	
	setBackgroundColor(createColor(50, 50, 50));
}

void update() {
	padUpdate();
}

void draw() {

}
