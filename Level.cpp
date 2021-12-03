#include "Level.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

Level::Level(){
    lvlname = "Beginnings";
    numMobs = 4;
    lvlMobs[0].setName("Green Slime");
    lvlMobs[1].setName("Blue Slime");
    lvlMobs[2].setName("Red Slime");
    lvlMobs[3].setName("Gold Slime");
    for(int i = 0; i < numMobs; i++){
        lvlMobs[i].setXp(10);
        lvlMobs[i].setMoney(10);
        lvlMobs[i].setDmg(10);
    }
}
Level::Level(string newName,int newNumMobs,Enemy newMobs[],int newDif){
    Level();
    lvlmulti = (1 * 2 * newDif);
    lvlname = newName;
    numMobs = 4;
    if(newNumMobs > numMobs){
        for(int i = 0;i < numMobs;i++){
            lvlMobs[i] = Mobs();
            lvlMobs[i].setName(newMobs[i].getName());
            lvlMobs[i].setXp(10*lvlmulti);
            lvlMobs[i].setMoney(10*lvlmulti);
            lvlMobs[i].setDmg(10*lvlmulti);
        }
    }else if(newNumMobs < numMobs){
        for(int i = 0; i < newNumMobs; i++){
            lvlMobs[i] = Mobs();
            lvlMobs[i].setName(newMobs[i].getName());
            lvlMobs[i].setXp(10*lvlmulti);
            lvlMobs[i].setMoney(10*lvlmulti);
            lvlMobs[i].setDmg(10*lvlmulti);
        }
        for(int i = newNumMobs;i < numMobs;i++){
            lvlMobs[i] = Mobs();
            lvlMobs[i].setXp(10*lvlmulti);
            lvlMobs[i].setMoney(10*lvlmulti);
            lvlMobs[i].setDmg(10*lvlmulti);
        }
    }else{
        for(int i = 0;i < numMobs;i++){
            lvlMobs[i] = Mobs();
            lvlMobs[i].setName(newMobs[i].getName());
            lvlMobs[i].setXp(10*lvlmulti);
            lvlMobs[i].setMoney(10*lvlmulti);
            lvlMobs[i].setDmg(10*lvlmulti);
        }
    }
}
void Level::setEnemys(Enemy enemys[]){
    for(int i = 0; i < 4; i++){
        enemys[i].setDmg(lvlMobs[i].getDmg());
        enemys[i].setMoney(lvlMobs[i].getMoney());
        enemys[i].setName(lvlMobs[i].getName());
        enemys[i].setXp(lvlMobs[i].getXp());
    }
}

Level::Mobs::Mobs(){
    name = "Slime";
    dmg = 10;
    money = 10;
    xp = 10;
}
//setters
void Level::Mobs::setName(string newName){
    name = newName;
}
void Level::Mobs::setDmg(int newDmg){
    dmg = newDmg;
}
void Level::Mobs::setMoney(int newMoney){
    money = newMoney;
}
void Level::Mobs::setXp(int newXp){
    xp = newXp;
}

//getter
int Level::Mobs::getDmg(){
    return dmg;
}
string Level::Mobs::getName(){
    return name;
}
int Level::Mobs::getMoney(){
    return money;
}
int Level::Mobs::getXp(){
    return xp;
}
