//
//  Game.h
//  Tanks
//
//  Created by Joseph Pecoraro on 1/20/13.
//  Copyright (c) 2013 Joseph Pecoraro. All rights reserved.
//

#ifndef __Tanks__Game__
#define __Tanks__Game__

#include <vector>
#include <iostream>
#include "World.h"

class Game {
    
public:
    Game();
    virtual ~Game();
    void runGame();
    World* getWorld() { return map; }
    void getNumPlayers();
    void initWorld();
    void addPlayers();
    void viewMain();
    void start();
    void play();
    void gameLoop();
    bool gameStatus(); //checks to see whether the game is still at a playable status. i.e. more than one person is still alive
    bool playAgain();
    Player* getChamp();
    void displayWinner(Player *p);
    void start2();
    
    
private:
    int missileVal1;
    int missileVal2;
    vector<Player> players;
    int numPlayers;
    World *map;
    Missile m;
    
    
};

#endif /* defined(__Tanks__Game__) */
