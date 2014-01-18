//
//  Game.cpp
//  Tanks
//
//  Created by Joseph Pecoraro on 1/20/13.
//  Copyright (c) 2013 Joseph Pecoraro. All rights reserved.
//

#include "Game.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

Game::Game() {
    start();
}

Game::~Game() {
    
}

void Game::getNumPlayers() {
    cout << "Please enter the number of players: ";
    cin >> numPlayers;
    players = *new vector<Player>(numPlayers);
}

void Game::addPlayers() {
    int v = 0;
    string n = "";
    stringstream ss;
    for (int i = 0; i < numPlayers; i ++) {
        v = i + 1;
        ss.str(string());
        ss << "Player " << v;
        n = ss.str();
        Player *p = new Player(n);
        players[i] = *p;
        map->addPlayer(*p, v);
    }
}

void Game::initWorld() {
    map = new World();
}

void Game::viewMain() {
    cout << "Welcome to Tanks!" << endl << endl;
}

//for first game
void Game::start() {
    initWorld();
    viewMain();
    getNumPlayers();
    addPlayers();
    gameLoop();
}

//for recurring games
void Game::start2() {
    initWorld();
    addPlayers();
    gameLoop();
}

//iterates through each players turn, checking if game status is broken during play
void Game::play() {
    for (int i =0; i < numPlayers; i ++) {
        Player *p = map->playersInWorld[i];
        if (p->isAlive()) {
            cout << p->getName() << ": " << "Enter an angle between 0 and 180 (0 is due-east and 180 is due-west): " << endl;
            cin >> missileVal2;
            cout << "Enter a velocity between 1 and 100" << endl;
            cin >> missileVal1;
            m = *new Missile(missileVal1, missileVal2);
            map->addMissile(m, *p);
            map->printMissileWorld();
            if (gameStatus() == false) break;
        }
    }
}

void Game::gameLoop() {
    map->printWorld();
    do {
        play();
    }
    while (gameStatus());
    Player* winner = getChamp();
    displayWinner(winner);
    if (playAgain()) start2();
}

//game status. true if at least 2 players are still alive.
bool Game::gameStatus() {
    int val = 0;
    for (int i = 0; i < numPlayers; i ++ ) {
        if (map->playersInWorld[i]->isAlive()) val++;
    }
    if (val < 2 ) return false;
    else return true;
}

Player* Game::getChamp() {
    for (int i = 0; i < numPlayers; i ++ ) {
        Player *p = map->playersInWorld[i];
        if (p->isAlive()) return p;
    }
}

void Game::displayWinner(Player *p) {
    cout << endl << "Congratulations " << p->getName() << ", you have won the Game!" << endl;
}

bool Game::playAgain() {
    string s;
    cout << "Play again? (y/n)";
    cin >> s;
    if (s == "y") return true;
    else return false;
}