/*
 * File:   Player.h
 * Author: Joseph
 *
 * Created on January 9, 2013, 3:53 PM
 */

#include <string>
#ifndef PLAYER_H
#define	PLAYER_H

using namespace std;

class Player {
public:
	Player() { }
    Player(string name);
    virtual ~Player();
    int getHealth() { return health; }
    int getXPosition() { return xPosition; }
    int getYPosition() { return yPosition; }
    void setXPosition(int x);
    void setYPosition(int y);
    void kill();
    bool hasX(int x);
    bool isAlive();
    string getName() { return name; }
    
private:
    string name;
    int health;
    int xPosition;
    int yPosition;
    int xCoordinates[3];
    int yCoordinates[3];
    bool alive;
};

#endif	/* TANK_H */

