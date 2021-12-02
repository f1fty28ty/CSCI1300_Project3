#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Items.h"
#include "Shop.h"
#include "Items.cpp"

using namespace std;

int Shop::getBalance(){
    return newPlayerMoney;
}

void Shop::setBalance(int playerMoney){
    newPlayerMoney = playerMoney;
}

int printShop();

string typeConverter(int index);

string CharConverter(char val);

char StringConverter(string nameval);

int reverseConverter(string inputstring);

int purchaseSwords(int money);

string atkItemName(int index);

int purchaseArmor(int money);

int sellItems(int money);

int buyPotions(int money);

string defItemName(int index);

int printShop(){
    Items Item1;
    Item1.populateStats();
    long int money = 10000000000000000;
    int whileop = 1;
    int switchop;
    int cost = 0;
    int index;
    char buy;
    char sell;
    while(whileop = 1){
        cout << "Welcome to XXXX shop!" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Purchase Swords" << endl;
        cout << "2. Purchase Armor" << endl;
        cout << "3. Sell Items" << endl;
        cout << "4. Purchase Potions" << endl;
        cout << "5. Exit Shop" << endl;
        cin >> switchop;
        switch(switchop){
            case 1:
            money = purchaseSwords(money);
            break;
            case 2: 
            money = purchaseArmor(money);
            case 3: 
            money = sellItems(money);
            break;
            case 4: 
            money = buyPotions(money);
            case 5:
            cout << "Good Luck on your travels!" << endl;
            whileop = 0;
            break;
            default:
            cout << "That input isn't recognized. Please enter an option between 1 and 3" << endl;
            break;
        }
    }
    return money;
}

string typeConverter(int index){
    string endval;
    if (index == 1) {
        endval == "s";
        return endval;
    }
    else if (index == 2){
        endval == "a";
        return endval;
    }
    else if (index == 3){
        endval == "b";
        return endval;
    }
    else if (index == 4){
        endval == "c";
        return endval;
    }
    else if (index == 5){
        endval == "d";
        return endval;
    }
    else if (index == 6){
        endval == "f";
        return endval;
    }
    else {
        return "";
    }
}


int reverseConverter(string inputstring){
    int endval;
    if (inputstring == "s") {
        endval = 1;
        return endval;
    }
    else if (inputstring == "a"){
        endval = 2;
        return endval;
    }
    else if (inputstring == "b"){
        endval = 3;
        return endval;
    }
    else if (inputstring == "c"){
        endval = 4;
        return endval;
    }
    else if (inputstring == "d"){
        endval = 5;
        return endval;
    }
    else if (inputstring == "f"){
        endval = 6;
        return endval;
    }
    else {
        return 0;
    }
}


string CharConverter(char val){
    string endval;
    if (val == 's') {
        endval == "s";
        return endval;
    }
    else if (val == 'a'){
        endval == "a";
        return endval;
    }
    else if (val == 'b'){
        endval == "b";
        return endval;
    }
    else if (val == 'c'){
        endval == "c";
        return endval;
    }
    else if (val == 'd'){
        endval == "d";
        return endval;
    }
    else if (val == 'f'){
        endval == "f";
        return endval;
    }
    else return "";
}

char StringConverter(string nameval){
    char endval;
    if (nameval == "s") {
        endval = 's';
        return endval;
    }
    else if (nameval == "a"){
        endval = 'a';
        return endval;
    }
    else if (nameval == "b"){
        endval = 'b';
        return endval;
    }
    else if (nameval == "c"){
        endval = 'c';
        return endval;
    }
    else if (nameval == "d"){
        endval = 'd';
        return endval;
    }
    else if (nameval == "f"){
        endval = 'f';
        return endval;
    }
}

int purchaseSwords(int money){
    Items Item1;
    int value;
    char buy;
    int price;
    cout << "Swords for purchase" << endl;
    for (int i = 0; i < 6; i++){
        price = Item1.getAtkPrice(typeConverter(i+1));
        Item1.setAtk(typeConverter(i+1));
        cout << "Item " << (i+1) << ": " << atkItemName(i) << " :: " << price << " Coins" <<  endl;
        cout << "Item " << (i+1) << "Stats: " << Item1.getAtk() << " Attack " << endl;
        cout << "\n";
    }
    cout << "Which sword would you like to buy?" << endl;
    cin >> value;
    if (Item1.getAtkName() != "j"){
        cout << "You must sell your currently equipped sword before purchasing a new one";
        cout << "Would you like to proceed?" << endl;
        cout << "[Y] [N]" << endl;
        cin >> buy;
        if (buy == 'y' || buy == 'Y') {
            money += Item1.getAtkPrice(Item1.getAtkName());
            money -= Item1.getAtkPrice(typeConverter(value));
            Item1.setAtk(typeConverter(value));
        }
        else {
            cout << "Transaction not completed. Please try again if this was a mistake." << endl;
        }
    }
    else {
        cout << "Would you like to purchase sword " << value << " ?" << endl;
        cout << "[Y] [N]" << endl;
        cin >> buy;
        if (buy == 'y' || buy == 'Y') {
            money -= Item1.getAtkPrice(typeConverter(value));
            Item1.setAtk(typeConverter(value));
        }
        else {
            cout << "Transaction not completed. Please try again if this was a mistake." << endl;
        }
    }
    return money;
}

string atkItemName(int index){
    string endval;
    if (index == 1) {
        endval == "Legendary Sword";
        return endval;
    }
    else if (index == 2){
        endval == "Mythical Sword";
        return endval;
    }
    else if (index == 3){
        endval == "Kings' Sword";
        return endval;
    }
    else if (index == 4){
        endval == "Knights' Sword";
        return endval;
    }
    else if (index == 5){
        endval == "Sqires' Sword";
        return endval;
    }
    else if (index == 6){
        endval == "Basic Sword";
        return endval;
    }
    else {
        return "";
    }
}

int purchaseArmor(int money){
    Items Item1;
    int value;
    char buy;
    int price;
    cout << "Armor sets for purchase" << endl;
    for (int i = 0; i < 6; i++){
        price = Item1.getDefPrice(typeConverter(i+1));
        Item1.setDef(typeConverter(i+1));
        cout << "Item " << (i+1) << ": " << defItemName(i) << " :: " << price << " Coins" <<  endl;
        cout << "Item " << (i+1) << "Stats: " << Item1.getDef() << " Attack " << endl;
        cout << "\n";
    }
    cout << "Which armor set would you like to buy?" << endl;
    cin >> value;
    if (Item1.getDefName() != "j"){
        cout << "You must sell your currently equipped armor set before purchasing a new one";
        cout << "Would you like to proceed?" << endl;
        cout << "[Y] [N]" << endl;
        cin >> buy;
        if (buy == 'y' || buy == 'Y') {
            money += Item1.getDefPrice(Item1.getDefName());
            money -= Item1.getDefPrice(typeConverter(value));
            Item1.setDef(typeConverter(value));
            Item1.setDefName(value);
        }
        else {
            cout << "Transaction not completed. Please try again if this was a mistake." << endl;
        }
    }
    else {
        cout << "Would you like to purchase armor set " << value << " ?" << endl;
        cout << "[Y] [N]" << endl;
        cin >> buy;
        if (buy == 'y' || buy == 'Y') {
            money -= Item1.getDefPrice(typeConverter(value));
            Item1.setDef(typeConverter(value));
            Item1.setDefName(value);
        }
        else {
            cout << "Transaction not completed. Please try again if this was a mistake." << endl;
        }
    }
    return money;
}

string defItemName(int index){
    string endval;
    if (index == 1) {
        endval == "Legendary Armor";
        return endval;
    }
    else if (index == 2){
        endval == "Mythical Armor";
        return endval;
    }
    else if (index == 3){
        endval == "Kings' Armor";
        return endval;
    }
    else if (index == 4){
        endval == "Knights' Armor";
        return endval;
    }
    else if (index == 5){
        endval == "Sqires' Armor";
        return endval;
    }
    else if (index == 6){
        endval == "Basic Armor";
        return endval;
    }
    else {
        return "";
    }
}

int sellItems(int money){
    Items Item1;
    char sell;
    int price;
    int input;
    // ask for input from miles on how inventory is checked
    if (Item1.getDefName() != "j" && Item1.getAtkName() != "j"){
        cout << "Which item would you like to sell?" << endl;
        if (Item1.getAtkName() == "j" && Item1.getDefName() != "j"){
            price = Item1.getDefPrice(Item1.getDefName());
            cout << "Armor: " << defItemName(reverseConverter(Item1.getDefName())) << " :: " << price << "coins" << endl;
            cout << "You have no sword to sell." << endl;
            cin >> sell;
            cout << "Sell this item?" << endl;
            cout << "[Y] [N]" << endl;
            if (sell == 'y' || sell == 'Y') {
                Item1.getDefPrice(Item1.getDefName());
                Item1.setDefName(0);
                Item1.setDef("j");
                money += Item1.getDefPrice(Item1.getAtkName());
                cout << "You don't have any armor equipped.You should consider purchasing some before you leave the shop." << endl;
            }
            else {
                cout << "Transaction not completed. Please try again if this was a mistake." << endl;
            }
        }
        else if (Item1.getDefName() == "j" && Item1.getAtkName() != "j"){
            price = Item1.getAtkPrice(Item1.getAtkName());
            cout << "You have no armor to sell." << endl;
            cout << " Sword: " << atkItemName(reverseConverter(Item1.getAtkName())) << " :: " << price << "coins" << endl;
            cout << "\n";
            cout << "Sell this item?" << endl;
            cout << "[Y] [N]" << endl;
            cin >> sell;
            if (sell == 'y' || sell == 'Y') {
                Item1.getAtkPrice(Item1.getAtkName());
                Item1.setAtkName(0);
                Item1.setAtk("j");
                money += Item1.getAtkPrice(Item1.getAtkName());
                cout << "You don't have a sword equipped.You should consider purchasing one before you leave the shop." << endl;
            }
            else {
                cout << "Transaction not completed. Please try again if this was a mistake." << endl;
            }
        }
        else {
            price = Item1.getDefPrice(Item1.getDefName());
            cout << "Armor: " << defItemName(reverseConverter(Item1.getDefName())) << " :: " << price << "coins" << endl;
            price = Item1.getAtkPrice(Item1.getAtkName());
            cout << " Sword: " << atkItemName(reverseConverter(Item1.getAtkName())) << " :: " << price << "coins" << endl;
            cout << "\n";
            cout << "Which of these items would you like to sell?" << endl;
            cout << "1. Sword    2. Armor     3. Both" << endl;
            cin >> input;
            if (input = 1){
                price = Item1.getAtkPrice(Item1.getAtkName());
                cout << " Sword: " << atkItemName(reverseConverter(Item1.getAtkName())) << " :: " << price << "coins" << endl;
                cout << "\n";
                cout << "Sell this item?" << endl;
                cout << "[Y] [N]" << endl;
                cin >> sell;
                if (sell == 'y' || sell == 'Y') {
                    Item1.getAtkPrice(Item1.getAtkName());
                    Item1.setAtkName(0);
                    Item1.setAtk("j");
                    money += Item1.getAtkPrice(Item1.getAtkName());
                    cout << "You don't have a sword equipped.You should consider purchasing one before you leave the shop." << endl;
            }
            else {
                cout << "Transaction not completed. Please try again if this was a mistake." << endl;
            }
            }
            else if (input = 2){
                price = Item1.getDefPrice(Item1.getDefName());
                cout << "Armor: " << defItemName(reverseConverter(Item1.getDefName())) << " :: " << price << "coins" << endl;
                cin >> sell;
                cout << "Sell this item?" << endl;
                cout << "[Y] [N]" << endl;
                if (sell == 'y' || sell == 'Y') {
                    Item1.getDefPrice(Item1.getDefName());
                    Item1.setDefName(0);
                    Item1.setDef("j");
                    money += Item1.getDefPrice(Item1.getAtkName());
                    cout << "You don't have any armor equipped.You should consider purchasing some before you leave the shop." << endl;
                }
                else {
                    cout << "Transaction not completed. Please try again if this was a mistake." << endl;
                }
            }
            else if (input = 3){
                price = Item1.getAtkPrice(Item1.getAtkName());
                cout << " Sword: " << atkItemName(reverseConverter(Item1.getAtkName())) << " :: " << price << "coins" << endl;
                price = Item1.getDefPrice(Item1.getDefName());
                cout << "Armor: " << defItemName(reverseConverter(Item1.getDefName())) << " :: " << price << "coins" << endl;
                cout << "Sell these items?" << endl;
                cout << "[Y] [N]" << endl;
                cin >> sell;
                if (sell == 'y' || sell == 'Y') {
                    Item1.getAtkPrice(Item1.getAtkName());
                    Item1.setAtkName(0);
                    Item1.setAtk("j");
                    money += Item1.getAtkPrice(Item1.getAtkName());
                    Item1.getDefPrice(Item1.getDefName());
                    Item1.setDefName(0);
                    Item1.setDef("j");
                    money += Item1.getDefPrice(Item1.getAtkName());
                    cout << "You don't have any gear equipped.You should consider purchasing more gear before you leave the shop." << endl;
            }
            }
            else {
               cout << "Transaction not completed. Please try again if this was a mistake." << endl; 
            }
        }
    }
    else{
        cout << "You have no items to sell" << endl;
    }
    return money;
}

int main(){
    printShop();
}