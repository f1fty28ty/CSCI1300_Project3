#include <iostream>
#include <vector>

using namespace std;

class Level{
public:
    Level(){
        lvlname = "Beginnings";
        numMobs = 4;
        lvlMobs[0].setName("Green Slime");
        lvlMobs[1].setName("Blue Slime");
        lvlMobs[2].setName("Red Slime");
        lvlMobs[3].setName("Gold Slime");
        for(int i = 0; i < numMobs; i++){
            lvlMobs[i].setXP(10);
            lvlMobs[i].setMoney(10);
            lvlMobs[i].setDmg(10);
        }
    }
    Level(string newName,int newNumMobs,Enemy newMobs[],int newDif){
        lvlname = newName;
        if(newNumMobs > numMobs){
            numMobs = 4;
        }else if(newNumMobs < numMobs){
            
        }
    }
    //get diff
    class Mobs{
    public:
        Enemy();
        //setters
        void setName(string newName);
        void setDmg(int newDmg);
        void setMoney(int newMoney);
        void setXp(int newXp);
        //getter
        int getDmg();
        string getName();
        int getMoney();
        int getXp();
    private:
        string name;
        int dmg;
        int money;
        int xp;
    };
private:
    string lvlname;
    Mobs lvlMobs[4];
    int numMobs;
    int lvlmulti;
};
