#ifndef Level
#define Level
#include <iostream>
#include <vector>
#include "Enemy.h"

using namespace std;

class Level{
public:
    Level();
    Level(string,int,Enemy,int);

    //mobs for the level.
    class Mobs{
    public:
        Mobs();
        //setters
        void setName(string);
        void setDmg(int);
        void setMoney(int);
        void setXp(int);
        //getter
        int getDmg();
        string getName();
        int getMoney();
        int getXp();
    private:
        string name;
        int dmg;
        int money;
        int xp;
    };
private:
    string lvlname;
    Mobs lvlMobs[4];
    int numMobs;
    int lvlmulti;
};
#endif
