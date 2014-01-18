/*
 * File:   Missile.cpp
 * Author: Joseph
 *
 * Created on January 9, 2013, 3:53 PM
 */

#define _USE_MATH_DEFINES
#include "Missile.h"
#include <math.h>

Missile::Missile(int velocity, int angle) {
    initialVelocity = velocity;
    angleDegrees = angle;
    degreesToRadians();
    calcXVelocity();
    calcinitYVelocity();
    findYVeloc();
    if (angleDegrees < 90) calcValues();
    else calcNegXValues();
}

Missile::~Missile() {
}

//unused
float Missile::getXPosition(float t) {
    return xVelocity*t;
}

//unused
float Missile::getYPosition(float t) {
    return (initYVelocity*t) - (.5*9.8*t*t);
}

void Missile::calcXVelocity() {
    xVelocity = initialVelocity*cos(angleRadians);
}

void Missile::calcinitYVelocity() {
    initYVelocity = initialVelocity*sin(angleRadians);
}

float Missile::calcYVelocity(float t) {
    return initYVelocity + -9.8*t;
}

void Missile::degreesToRadians() {
    angleRadians = angleDegrees*M_PI/180.0;
}

//finds 100 y velocity for given time intervals of +.4(seconds)
void Missile::findYVeloc() {
    int counter = 0;
    for (float t = 0; t < 40; t += .4) {
        yVeloc[counter] = int(calcYVelocity(t)+.5);
        counter ++;
    }
}

//used for the shot trajectory. Based on the size of the constant x velocity in comparison with the changing y velocity, the loop decides how many times to move x for the number of times it moves y. 
void Missile::calcValues() {
    float x = xVelocity;
    int y;
    int index = 1;
    int dif;
    xVals[0] = 0;
    yVals[0] = 0;
    for (int i = 1; i < 100; i ++) {
        if (index >= 100) break;
        y = yVeloc[i];
        if (y>x) {
            dif = int ((y/(float)x) +.5);
            
            if (dif > 1) {
                for (int j = 0; j < dif; j ++) {
                    yVals[index] = 1;
                    xVals[index] = 0;
                    index++;
                    if (index >= 100) break;
                }
                xVals[index - dif] = 1;
            }
            else {
                xVals[index] = 1;
                yVals[index] = 1;
                index++;
            }
        }
        else if ((y*-1) > x) {
            y = y*-1;
            dif = int (y/(float)x) +.5;
            
            if (dif > 1) {
                for (int j = 0; j < dif; j ++) {
                    yVals[index] = -1;
                    xVals[index] = 0;
                    index++;
                    if (index >= 100) break;
                }
                xVals[index - dif] = 1;
            }
            else {
                xVals[index] = 1;
                yVals[index] = -1;
                index++;
            }
        }
        else if (fabs(y) < 7) {
            xVals[index] = 1;
            yVals[index] = 0;
            index++;
        }
        else if (y < 0) {
            y=y*-1;
            dif = int ((x/(float)y) +.5);
            
            if (dif > 1) {
                for (int j = 0; j < dif; j ++) {
                    xVals[index] = 1;
                    yVals[index] = 0;
                    index++;
                    if (index >= 100) break;
                }
                yVals[index - dif] = -1;
            }
            else {
                xVals[index] = 1;
                yVals[index] = -1;
                index++;
            }
        }
        else {
            dif = int ((x/(float)y) +.5);
            
            if (dif > 1) {
                for (int j = 0; j < dif; j ++) {
                    xVals[index] = 1;
                    yVals[index] = 0;
                    index++;
                    if (index >= 100) break;
                }
                yVals[index - dif] = 1;
            }
            else {
                xVals[index] = 1;
                yVals[index] = 1;
                index++;
            }
        }
    }
}

//same as above but for negative x values (angle greater than 90
void Missile::calcNegXValues() {
    float x = -1 * xVelocity;
    int y;
    int index = 1;
    int dif;
    xVals[0] = -4;
    yVals[0] = 0;
    for (int i = 1; i < 100; i ++) {
        if (index >= 100) break;
        y = yVeloc[i];
        if (y>x) {
            dif = int ((y/(float)x) +.5);
            
            if (dif > 1) {
                for (int j = 0; j < dif; j ++) {
                    yVals[index] = 1;
                    xVals[index] = 0;
                    index++;
                    if (index >= 100) break;
                }
                xVals[index - dif] = -1;
            }
            else {
                xVals[index] = -1;
                yVals[index] = 1;
                index++;
            }
        }
        else if ((y*-1) > x) {
            y = y*-1;
            dif = int (y/(float)x) +.5;
            
            if (dif > 1) {
                for (int j = 0; j < dif; j ++) {
                    yVals[index] = -1;
                    xVals[index] = 0;
                    index++;
                    if (index >= 100) break;
                }
                xVals[index - dif] = -1;
            }
            else {
                xVals[index] = -1;
                yVals[index] = -1;
                index++;
            }
        }
        else if (fabs(y) < 7) {
            xVals[index] = -1;
            yVals[index] = 0;
            index++;
        }
        else if (y < 0) {
            y=y*-1;
            dif = int ((x/(float)y) +.5);
            
            if (dif > 1) {
                for (int j = 0; j < dif; j ++) {
                    xVals[index] = -1;
                    yVals[index] = 0;
                    index++;
                    if (index >= 100) break;
                }
                yVals[index - dif] = -1;
            }
            else {
                xVals[index] = -1;
                yVals[index] = -1;
                index++;
            }
        }
        else {
            dif = int ((x/(float)y) +.5);
            
            if (dif > 1) {
                for (int j = 0; j < dif; j ++) {
                    xVals[index] = -1;
                    yVals[index] = 0;
                    index++;
                    if (index >= 100) break;
                }
                yVals[index - dif] = 1;
            }
            else {
                xVals[index] = -1;
                yVals[index] = 1;
                index++;
            }
        }
    }
}
