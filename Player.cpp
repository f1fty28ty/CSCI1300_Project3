#include "Player.h"

//Constructor   
Player::Player(){
    currentHealth = 100;
    maxHealth = 100;
    name = "";
    dmg = 10;
    def = 10;
    lvl = 0;
    currentExp = 0;
    maxExp = 100;
    money = 100;
    armor = 'j';
    sword = 'j';
    key = "";
    numPotion = 0;
}

//Setters
void Player::heal(){
    if(numPotion > 0){
        currentHealth = maxHealth;
        numPotion--;
    }else{
        cout << "Sorry you do not have enough potions to heal!" << endl;
    }
}

int Player::addExp(int addedExp){
    currentExp += addedExp;
    if(currentExp >= maxExp){
        lvlUp();
        currentExp = currentExp - maxExp;
    }
    return currentExp;
}

void Player::setName(string newName){
    name = newName;
}
void Player::lvlUp(){
    lvl++;
    dmg += 10;
    def += 10;
    currentHealth += 5;
    money += (lvl * 20);
    currentExp = 0;
    maxExp *= 2;
}
void Player::setDmg(int newDmg){
    dmg = newDmg;
}
void Player::setDef(int newDef){
    def = newDef;
}
void Player::addMoney(int newMoney){
    money += newMoney;
}
void Player::setMoney(int newMoney){
    money = newMoney;
}
void Player::setSword(char newSword){
    sword = newSword;
}
void Player::setArmor(char newArmor){
    armor = newArmor;
}
void Player::takeDmg(int dmg){
    currentHealth -= dmg;
}
void Player::setCurrentHealth(int newHp){
    currentHealth = newHp;
}
void Player::setMaxHealth(int newHp){
    maxHealth = newHp;
}
void Player::setCurrentExp(int newXp){
    currentExp = newXp;
}
void Player::setMaxExp(int newXp){
    maxExp = newXp;
}
void Player::setLvl(int newLvl){
    lvl = newLvl;
}
void Player::setKey(string newKey){
    key = newKey;
}
void Player::setPotions(int newPotion){
    numPotion = newPotion;
}
//Getter
string Player::getName(){
    return name;
}
int Player::getLvl(){
    return lvl;
}
int Player::getDmg(){
    return dmg;
}
int Player::getDef(){
    return def;
}
int Player::getMoney(){
    return money;
}
int Player::getCurrentHealth(){
    return currentHealth;
}
int Player::getMaxHealth(){
    return maxHealth;
}
int Player::getCurrentExp(){
    return currentExp;
}
int Player::getMaxExp(){
    return maxExp;
}
string Player::getKey(){
    return key;
}
int Player::getPotions(){
    return numPotion;
}
char Player::getSword(){
    return sword;
}
char Player::getArmor(){
    return armor;
}
