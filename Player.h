#include <iostream>

using namespace std;

class Player{
public:
    //Constructor   
    Player();
    //Setters
    void heal();
    int addExp(int addedExp);
    void setName(string newName);
    void lvlUp();
    void setDmg(int newDmg);
    void setDef(int newDef);
    void addMoney(int newMoney);
    void setMoney(int newMoney);
    void setSword(char newSword);
    void setArmor(char newArmor);
    void takeDmg(int dmg);
    void setCurrentHealth(int newHp);
    void setMaxHealth(int newHp);
    void setCurrentExp(int newXp);
    void setMaxExp(int newXp);
    void setLvl(int newLvl);
    void setKey(string newKey);
    void setPotions(int newPotion);
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
    string getKey();
    int getPotions();
    char getSword();
    char getArmor();
private:
    int currentHealth;
    int maxHealth;
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