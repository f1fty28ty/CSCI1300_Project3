//Miles Silveria
#include "Enemy.h"

Enemy::Enemy(){
    name = "Slime";
    dmg = 10;
    money = 10;
    xp = 10;
}
//setters
void Enemy::setName(string newName){
    name = newName;
}
void Enemy::setDmg(int newDmg){
    dmg = newDmg;
}
void Enemy::setMoney(int newMoney){
    money = newMoney;
}
void Enemy::setXp(int newXp){
    xp = newXp;
}

//getter
int Enemy::getDmg(){
    return dmg;
}
string Enemy::getName(){
    return name;
}
int Enemy::getMoney(){
    return money;
}
int Enemy::getXp(){
    return xp;
}