//Miles Silveria
#include <iostream>

using namespace std;

class Player{
public:
    //Constructor   
    Player();
    //Setters
    void heal();
    void addExp(int addedExp);
    string setName(string newName);
    void lvlUp();
    void setDmg(int newDmg);
    void setDef(int newDef);
    void addMoney(int newMoney);
    void setSword(char newSword);
    void setArmor(char newArmor);
    void takeDmg (int dmg);
    //Getter
    string getName();
    int getLvl();
    int getDmg();
    int getDef();
    int getMoney();
    int getCurrentHealth();
    int getMaxHealth();
    int getCurrentExp();
    int getMaxExp();
    char getSword();
    char getArmor();
    void printProfile();
private:
    string name;
    int currentHealth = 100;
    int maxHealth = 100;
    int dmg;
    int def;
    int lvl;
    int currentExp;
    int maxExp;
    int money;
    char armor;
    char sword;
    string key;
    int numPotion;
};