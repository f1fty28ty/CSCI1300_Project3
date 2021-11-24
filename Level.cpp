#include "Level.h"

Level::Mobs::Enemy(){
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
