/*
 * File:   World.h
 * Author: Joseph
 *
 * Created on January 9, 2013, 12:55 AM
 */

#include "Player.h"
#include "Missile.h"
#include <vector>
#ifndef WORLD_H
#define	WORLD_H

using namespace std;

class World {
public:
    World();
    virtual ~World();
    void generateTerrain(); //randomly generate world/terrain
    void reset();
    int getAltitude(int x);// returns the height of the terrain at the given x value
    void printWorld();
    void addSpaces();
    void addPlayer(Player &p, int n);
    void addMissile(Missile m, Player p);
    void missileToGrid();
    void printMissileWorld();
    Player* getPlayer(int xPos);
    bool xyIsLessEqualTX(int x, int y);
    bool xyIsLessEqualP(int x, int y);
    void killPlayer(int x, int y);
    
    vector<Player*> playersInWorld;
    
private:
    char grid[100][30];
    char worldPostMissile[100][30];
    
};

#endif	/* BACKGROUNDGRID_H */

