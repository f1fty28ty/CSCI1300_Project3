#include <iostream>
#include "Enemy.h"
#include "Items.h"
#include "Player.h"
#include "Shop.h"

using namespace std;

int main(){
    Player p1 = Player();
    Enemy slime = Enemy();
    // set player name
    string name;
    cin >> name;
    p1.setName(name);
    p1.printProfile();

    int dmg = slime.getDmg();
    cout << slime.getName() << " Hits " << p1.getName() << " for " << dmg << " points." << endl;
    p1.takeDmg(dmg);
    p1.heal();
    //checking if it adds exp and lvls up;
    p1.addExp(200);
    p1.printProfile();
    //check items
    Items sword = Items("BasicSword", "");
    Items armor = Items("", "BasicArmor");
    sword.setAtk(200);
    armor.setDef(200);
    p1.setSword('f');
    p1.setArmor('f');
    p1.setDmg(sword.getAtk());
    p1.setDef(armor.getDef());
    p1.printProfile();
    //checking shop
    int money = p1.getMoney();
    Shop shop = Shop(money);
    cout << "Balance " << shop.getBalance() << endl; 
}