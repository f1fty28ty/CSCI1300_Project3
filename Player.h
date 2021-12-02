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
    void setName(string newName);
    void lvlUp();
    void setDmg(int newDmg);
    void setDef(int newDef);
    void addMoney(int newMoney);
    void setMoney(int newMoney);
    void setSword(char newSword);
    void setArmor(char newArmor);
    void takeDmg (int dmg);
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
    char getSword();
    char getArmor();
    string getKey();
    int getPotions();
private:
    string name;
    long int currentHealth;
    long int maxHealth;
    long int dmg;
    long int def;
    long int lvl;
    long int currentExp;
    long int maxExp;
    long int money;
    char armor;
    char sword;
    string key;
    long int numPotion;
};
