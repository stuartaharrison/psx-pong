/* constants.h
 * Definitions and Functions for the Game Pong on PSX
 * Created by: S. Harrison
 * Date: 15-09-2018
 */
#pragma once


typedef struct {
	int x, y, height;
	Line line;
} Bat;

typedef struct {
	int size, x, y, is_moving, speed_x, speed_y;
	Box box;
} Ball;

typedef struct {
	int score_left, score_right
} Scoreboard;