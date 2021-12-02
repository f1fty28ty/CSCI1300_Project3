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
    string atkstat[7];
    string atkname[7];
    string atkprice[7];
    string defstat[7];
    string defname[7];
    string defprice[7];
    string atkitemname = "j";
    string defitemname = "j";
    string itematk = "j";
    string itemdef = "j";
    int atk;
    int def;
    string statFile;
};

