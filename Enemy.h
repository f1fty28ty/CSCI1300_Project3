//Miles Silveria
#ifndef ENEMY
#define ENEMY
#include <iostream>
#include <string>

using namespace std;

class Enemy{
public:
    Enemy();
    //setters
    void setName(string newName);
    void setDmg(int newDmg);
    void setMoney(int newMoney);
    void setXp(int newXp);
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
#endif