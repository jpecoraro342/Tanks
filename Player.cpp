/*
 * File:   Player.cpp
 * Author: Joseph
 *
 * Created on January 9, 2013, 3:53 PM
 */

#include "Player.h"

Player::Player(string n) {
    name = n;
    health = 1;
    alive = true;
}

Player::~Player() {
}

void Player::setXPosition(int x) {
    xPosition = x;
    xCoordinates[0] = x -1;
    xCoordinates[1] = x;
    xCoordinates[2] = x+1;
}

void Player::setYPosition(int y) {
    yPosition = y;
    yCoordinates[0] = y +1;
    yCoordinates[1] = y;
    yCoordinates[2] = y-1;
}

//changes alive status
void Player::kill() {
    alive = false;
}

//checks if player is alive
bool Player::isAlive() {
    return alive;
}

//checks if the player contains a certain x coordinate. Used for getPlayer(int x) in world class
bool Player::hasX(int x) {
    for (int i =0; i < 3; i ++) {
        if (x == xCoordinates[i]) return true;
    }
    return false;
}



