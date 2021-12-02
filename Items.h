#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Items{

    public:
    Items();
    int getAtk();
    void setAtk(string itematk);
    string getAtkName();
    string getDefName();
    void setAtkName(int index);
    void setDefName(int index);
    int getDef();
    void setDef(string itemdef);
    void populateStats();
    int getAtkPrice(string itematk);
    int getDefPrice(string itemdef);

    private:
    int index;
    long int atkstat[7];
    string atkname[7];
    long int atkprice[7];
    long int defstat[7];
    string defname[7];
    long int defprice[7];
    string atkItemName;
    string defItemName;
    string itematk;
    string itemdef;
    int atk;
    int def;
    string statFile;
};

