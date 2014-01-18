/*
 * File:   Missile.h
 * Author: Joseph
 *
 * Created on January 9, 2013, 3:53 PM
 */

#ifndef MISSILE_H
#define	MISSILE_H

class Missile {
public:
    Missile(){ }
    Missile(int velocity, int angle);
    float getXPosition(float t);
    float getYPosition(float t);
    void calcXVelocity();
    void calcinitYVelocity();
    void degreesToRadians();
    void findYVeloc();
    void calcValues();
    void calcNegXValues(); // for angle > 90
    float calcYVelocity(float t);
    
    float xVelocity;
    
    int xVals[100];
    int yVals[100];
    int yVeloc[100];
    
    virtual ~Missile();
private:
    float initYVelocity;
    int angleDegrees;
    float angleRadians;
    int initialVelocity;
    
};

#endif	/* MISSILE_H */

