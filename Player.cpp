#include "Player.h"

//Constructor   
Player::Player(){
    currentHealth = 100;
    name = "";
    dmg = 10;
    def = 10;
    lvl = 0;
    currentExp = 0;
    maxExp = 100;
    money = 100;
    armor = '';
    sword = '';
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

string Player::setName(string newName){
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
    money += newMoney
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
char Player::getSword(){
    switch(sword){
    case 's':
        cout << "Sword: Legendary Sword" << endl;
    break;
    case 'a':
        cout << "Sword: Mythical Sword" << endl;
    break;
    case 'b':
        cout << "Sword: Kings' Sword" << endl;
    break;
    case 'c':
        cout << "Sword: Knights' Sword" << endl;
    break;
    case 'd':
        cout << "Sword: Sqires' Sword" << endl;
    break;
    case 'f':
        cout << "Sword: Basic Sword" << endl;
    break;
    default:
        cout << "Sword: N/A" << endl;
    break;
    }
    return sword;
}
char Player::getArmor(){
    switch(armor){
        case 's':
            cout << "Armor: Legendary Armor" << endl;
        break;
        case 'a':
            cout << "Armor: Mythical Armor" << endl;
        break;
        case 'b':
            cout << "Armor: Kings' Armor" << endl;
        break;
        case 'c':
            cout << "Armor: Knights' Armor" << endl;
        break;
        case 'd':
            cout << "Armor: Sqires' Armor" << endl;
        break;
        case 'f':
            cout << "Armor: Basic Armor" << endl;
        break;
        default:
            cout << "Armor: N/A" << endl;
        break;
    }
    return armor;
}
void Player::printProfile(){
    cout << "==========" << name << "'s Profile==========" << endl;
    cout << "Level: " << lvl << endl;
    cout << "Health: " << currentHealth << "/" << maxHealth << endl;
    cout << "Damage: "<< dmg << endl;
    cout << "Defense: " << def << endl;
    cout << "Gold Coins: " << money << endl;
    getSword();
    getArmor();
    cout << "Health Potions: " << numPotion << endl;
    if(key == ""){
        cout << "Key: None" << endl;
    }else{
        cout << "Key: " << key << endl;
    }
}