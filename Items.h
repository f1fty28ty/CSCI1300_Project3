#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Items{

    public:
    Items(string atkName, string defName);
    string getAtkName();
    void setAtkName(string newAtkName);
    int getAtk();
    void setAtk(int newAtk);
    string getDefName();
    void setDefName(string newDefName);
    int getDef();
    void setDef(int newDef);
    void populateStats(string statFile, string itemName);

    private:
    string loadoutStats[3];
    string atkName;
    string defName;
    string newAtkName;
    string newDefName;
    int atk;
    int def;
    int newAtk;
    int newDef;
    string statFile;
};
