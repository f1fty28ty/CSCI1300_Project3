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
    lvlmulti = (1 * 10 * newDif);
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

void Level::adv(Player player1){
    srand(time(NULL));
    int ran = (rand() % 4) + 0;
    int playerHealth = player1.getCurrentHealth();
    int playerDef = player1.getDef();
    int playerDmg = player1.getDmg();
    int playerXp = player1.getCurrentExp();
    int mobDmg = (rand() % lvlMobs[ran].getDmg()) + 1;
    string mobName = lvlMobs[ran].getName();
    int mobXp = (rand() % lvlMobs[ran].getXp()) + 1;
    int mobMoney = (rand() % lvlMobs[ran].getMoney()) + 1;
    if((playerDef <= mobDmg || playerDmg > mobDmg) && (playerHealth -= mobDmg) > 0){
        playerHealth -= mobDmg - (playerDmg / 2);
        cout << player1.getName() << " Has Defeated a(n) " << mobName << "!" << endl;
        cout << player1.getName() << " got +" << mobXp << "XP and +" << mobMoney << "!" << endl;
        cout << "HP left " << playerHealth << "/" << player1.getMaxHealth() << endl;
        player1.addExp(mobXp);
        player1.addMoney(mobMoney);
        player1.setCurrentHealth(playerHealth);
    }else if(playerDef > mobDmg){
        cout << player1.getName() << " Has Defeated a(n) " << mobName << "!" << endl;
        cout << player1.getName() << " got +" << mobXp << "XP and +" << mobMoney << "!" << endl;
        cout << "HP left " << playerHealth << "/" << player1.getMaxHealth() << endl;
        player1.addExp(mobXp);
        player1.addMoney(mobMoney);
    }else if((playerHealth -= mobDmg) <= 0){
        cout << player1.getName() << "has died and lost some Money" << endl;
        player1.setMoney(player1.getMoney() - 150);
    }else{
        playerHealth -= mobDmg - (playerDmg / 2);
        cout << player1.getName() << " Has Defeated a(n) " << mobName << "!" << endl;
        cout << player1.getName() << " got +" << mobXp << "XP and +" << mobMoney << "!" << endl;
        cout << "HP left " << playerHealth << "/" << player1.getMaxHealth() << endl;
        player1.addExp(mobXp);
        player1.addMoney(mobMoney); 
        player1.setCurrentHealth(playerHealth);
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
