//Miles Silveria
#include <iostream>

using namespace std;

class Player{
public:
    //Constructor   
    Player();
    //Setters
    void heal();
    int addExp(int addedExp);
    string setName(string newName);
    void lvlUp();
    void setDmg(int newDmg);
    void setDef(int newDef);
    void addMoney(int newMoney);
    void setSword(char newSword);
    void setArmor(char newArmor);
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
    int currentHealth;
    const int maxHealth;
    string name;
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
