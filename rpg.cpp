#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//#include "Enemy.h"
#include "Items.h"
//#include "Level.h"
#include "Map.h"
#include "Player.h"
#include "Shop.h"

using namespace std;

int split (string str, char delim, string tempArr[], int arrSize);
void printProfile(Player player1);
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

int main(){
    //setting stuff for player
    //checks if there is a previous player on file
    //Will always play on that save for convenience
    Player player1 = Player();
    string playerfileArr[13];
    ifstream playerFile;
    playerFile.open("player.txt");
    string line;
    long int num;
    char chars;
    for (int i = 0; i < 13; i++){
        switch(i){
            case 0:
                getline(playerFile,line);
                num = stol(line);
                player1.setCurrentHealth(num);
            break;
            case 1:
                getline(playerFile,line);
                num = stol(line);
                player1.setMaxHealth(num);
            break;
            case 2:
                getline(playerFile,line);
                player1.setName(line);
            break;
            case 3:
                getline(playerFile,line);
                num = stol(line);
                player1.setDmg(num);
            break;
            case 4:
                getline(playerFile,line);
                num = stol(line);
                player1.setDef(num);
            break;            
            case 5:
                getline(playerFile,line);
                num = stol(line);
                player1.setLvl(num);
            break;            
            case 6:
                getline(playerFile,line);
                num = stol(line);
                player1.setCurrentExp(num);
            break;            
            case 7:
                getline(playerFile,line);
                num = stol(line);
                player1.setMaxExp(num);
            break;
            case 8:
                getline(playerFile,line);
                num = stol(line);
                player1.setMoney(num);
            break;
            case 9:
                getline(playerFile,line);
                chars = line[0];
                player1.setArmor(chars);
            break;
            case 10:
                getline(playerFile,line);
                chars = line[0];
                player1.setSword(chars);
            break;            
            case 11:
                getline(playerFile,line);
                player1.setKey(line);
            break;            
            case 12:
                getline(playerFile,line);
                num = stol(line);
                player1.setPotions(num);
            break;            
        }
    }
    //stuff for the map
    Map map;
    map.spawnLevel(1, 2);
    map.spawnLevel(1, 5);
    map.spawnLevel(1, 8);
    map.spawnLevel(4, 2);
    map.spawnLevel(4, 5);
    map.spawnLevel(4, 8);
    map.spawnShop(2, 5);
    map.spawnShop(3, 5);
    //Level stuff
    //Level levels[6];
    char move;  // for storing user input
    int userInput;
    int level;

    cout << "Would you like to start the Game" << endl;
    cout << "1 = Yes, 0 = No" << endl;
    cin >> userInput;
    while(userInput == 1){
        cout << "Levels from L-R" << endl;
        cout << "0 1 2" << endl;
        cout << "3 4 5" << endl;
        cout << "Press p to see your Profile" << endl;
        cout << "Press x to Exit the Game and " << endl;
        map.displayMap();  // pretty print map_data in terminal

        cout << "Valid moves are: " << endl; 
        map.displayMoves();  // give user a menu of valid moves to pick from
        
        cout << "Input a move: "; 
        cin >> move;
        cout << endl;
        if(move == 'x'){
            break;
        }else if(move == 'p'){
            printProfile(player1);
        }else{
            map.executeMove(move);  // move the player on map based on user input
        }
        
        if (map.isLevelLocation()) {
            cout << "You're at a Level!" << endl;
            cout << "Would you like to enter" << endl;
            cout << "1 = Yes, 0 = No" << endl;
            cin >> userInput;
            if(map.getPlayerColPosition() == 1 && map.getPlayerRowPosition() == 2){
                level = 0;
            }
            if(map.getPlayerColPosition() == 1 && map.getPlayerRowPosition() == 5){
                level = 1;
            }
            if(map.getPlayerColPosition() == 1 && map.getPlayerRowPosition() == 8){
                level = 2;
            }
            if(map.getPlayerColPosition() == 4 && map.getPlayerRowPosition() == 2){
                level = 3;
            }
            if(map.getPlayerColPosition() == 4 && map.getPlayerRowPosition() == 5){
                level = 4;
            }
            if(map.getPlayerColPosition() == 4 && map.getPlayerRowPosition() == 8){
                level = 5;
            }
            cout << "Level: " << level << endl;
            if(userInput == 1){
                while(userInput != 0){
                    cout << "===What would you like to do===" << endl;
                    cout << "1: Adventure" << endl;
                    cout << "2: Heal" << endl;
                    cout << "0: Leave" << endl;
                    cin >> userInput;
                }
            }else if(userInput == 0){
                cout << "Alright, Back to Map" << endl;
            }else{
                cout << "Invalid Input, Back to Map" << endl;
            }
            
        }

        if (map.isShopLocation()) {
            cout << "You've encountered a Shop!" << endl;
            cout << "Would you like to enter" << endl;
            cout << "1 = Yes, 0 = No" << endl;
            cin >> userInput;
            if(userInput == 1){
                printShop();
            }else{
                cout << "Alright bye." << endl;
            }
            
        }
    }

}

void printProfile(Player player1){
    cout << "==========" << player1.getName() << "'s Profile==========" << endl;
    cout << "Level: " << player1.getLvl() << endl;
    cout << "Health: " << player1.getCurrentHealth() << "/" << player1.getMaxHealth() << endl;
    cout << "Damage: "<< player1.getDmg() << endl;
    cout << "Defense: " << player1.getDef() << endl;
    cout << "Gold Coins: " << player1.getMoney() << endl;
    switch(player1.getSword()){
    case 's':
        cout << "Sword: Legendary Sword" << endl;
    break;
    case 'a':
        cout << "Sword: Mythical Sword" << endl;
    break;
    case 'b':
        cout << "Sword: Kings' Sword" << endl;
    break;
    case 'c':
        cout << "Sword: Knights' Sword" << endl;
    break;
    case 'd':
        cout << "Sword: Sqires' Sword" << endl;
    break;
    case 'f':
        cout << "Sword: Basic Sword" << endl;
    break;
    default:
        cout << "Sword: N/A" << endl;
    break;
    }
    switch(player1.getArmor()){
    case 's':
        cout << "Armor: Legendary Armor" << endl;
    break;
    case 'a':
        cout << "Armor: Mythical Armor" << endl;
    break;
    case 'b':
        cout << "Armor: Kings' Armor" << endl;
    break;
    case 'c':
        cout << "Armor: Knights' Armor" << endl;
    break;
    case 'd':
        cout << "Armor: Sqires' Armor" << endl;
    break;
    case 'f':
        cout << "Armor: Basic Armor" << endl;
    break;
    default:
        cout << "Armor: N/A" << endl;
    break;
    }
    cout << "Health Potions: " << player1.getPotions() << endl;
    if(player1.getKey() == "None"){
        cout << "Key: None" << endl;
    }else{
        cout << "Key: " << player1.getKey() << endl;
    }
    cout << "=================================================\n\n" << endl;
    cout << "Scroll up to see Profile.\n";
}

int split (string str, char delim, string tempArr[], int arrSize){
    int strLen = str.length();
    string strDelim = "";
    strDelim += delim;
    int arrPos = 0;
    int startOfWord = 0;
    int endOfWord = 0;
    int numOfDelim = 0;

    //First check
    if(str == ""){
        return 0;
    }
    //Second check
    for(int y = 0; y < strLen;y++){
        if(str.substr(y,1) == strDelim){
            numOfDelim++;
        }
    }
    if(numOfDelim == 0){
        tempArr[0] = str;
        return 1;
    }
    int maxDelim = numOfDelim;
    numOfDelim = 0;
    //third Check
    if(maxDelim >= arrSize){ //runs till done
        for(int j = 0; j < strLen; j++){
            if(tempArr[0] != "" && str.substr(j, 1) == strDelim){ 
                endOfWord = j;
                endOfWord = endOfWord - startOfWord; 
                tempArr[arrPos] = str.substr(startOfWord, endOfWord);
                startOfWord = j + 1;
                arrPos++;
                numOfDelim++;
            }else if (tempArr[0] == "" && str.substr(j, 1) == strDelim){
                tempArr[arrPos] = str.substr(startOfWord,j);
                startOfWord = j + 1;
                arrPos++;
                numOfDelim++;
            }
        }
        return -1;
    }
    numOfDelim = 0;
    for(int j = 0; j < strLen; j++){
        if(tempArr[0] != "" && str.substr(j, 1) == strDelim){  // checks if temparray[0] is not equal to nothing
            endOfWord = j;//j is the position of delim
            endOfWord = endOfWord - startOfWord; //get length for substr
            tempArr[arrPos] = str.substr(startOfWord, endOfWord);// put it in
            startOfWord = j + 1; // j is the delim and we dont want that so plus 1
            arrPos++; //next position in array
            numOfDelim++;
        }else if (tempArr[0] == "" && str.substr(j, 1) == strDelim){ // checks if temparray[0] is equal to nothing
            tempArr[arrPos] = str.substr(startOfWord,j);
            startOfWord = j + 1;
            arrPos++;
            numOfDelim++;
        }else if(numOfDelim == maxDelim){//last word doesnt have a delim at end
            endOfWord = strLen;
            endOfWord = endOfWord - startOfWord;
            tempArr[arrPos] = str.substr(startOfWord, endOfWord);
        }
    }
    
    return arrPos + 1; //arr plus one because it was printing out 1 less
    
}

int printShop(){
    Items Item1;
    Item1.populateStats();
    long int money = 100000000;
    int whileop = 1;
    int switchop;
    int cost = 0;
    int index;
    char buy;
    char sell;
    while(whileop == 1){
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
            //money = buyPotions(money);
            cout << "wip" << endl;
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
        endval = "s";
        return endval;
    }
    else if (index == 2){
        endval = "a";
        return endval;
    }
    else if (index == 3){
        endval = "b";
        return endval;
    }
    else if (index == 4){
        endval = "c";
        return endval;
    }
    else if (index == 5){
        endval = "d";
        return endval;
    }
    else if (index == 6){
        endval = "f";
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
        endval = "s";
        return endval;
    }
    else if (val == 'a'){
        endval = "a";
        return endval;
    }
    else if (val == 'b'){
        endval = "b";
        return endval;
    }
    else if (val == 'c'){
        endval = "c";
        return endval;
    }
    else if (val == 'd'){
        endval = "d";
        return endval;
    }
    else if (val == 'f'){
        endval = "f";
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
    else return 'z';
}

int purchaseSwords(int money){
    Items Item1;
    int value;
    char buy;
    int price;
    cout << "Swords for purchase" << endl;
    for (int i = 1; i < 7; i++){
        price = Item1.getAtkPrice(typeConverter(i));
        Item1.setAtk(typeConverter(i));
        cout << "Item " << i << ": " << atkItemName(i) << " :: " << price << " Coins" <<  endl;
        cout << "Item " << i << "Stats: " << Item1.getAtk() << " Attack " << endl;
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
        endval = "Legendary Sword";
        return endval;
    }
    else if (index == 2){
        endval = "Mythical Sword";
        return endval;
    }
    else if (index == 3){
        endval = "Kings' Sword";
        return endval;
    }
    else if (index == 4){
        endval = "Knights' Sword";
        return endval;
    }
    else if (index == 5){
        endval = "Sqires' Sword";
        return endval;
    }
    else if (index == 6){
        endval = "Basic Sword";
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
    for (int i = 1; i < 7; i++){
        price = Item1.getDefPrice(typeConverter(i));
        Item1.setDef(typeConverter(i));
        cout << "Item " << (i) << ": " << defItemName(i) << " :: " << price << " Coins" <<  endl;
        cout << "Item " << (i) << "Stats: " << Item1.getDef() << " Attack " << endl;
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
        endval = "Legendary Armor";
        return endval;
    }
    else if (index == 2){
        endval = "Mythical Armor";
        return endval;
    }
    else if (index == 3){
        endval = "Kings' Armor";
        return endval;
    }
    else if (index == 4){
        endval = "Knights' Armor";
        return endval;
    }
    else if (index == 5){
        endval = "Sqires' Armor";
        return endval;
    }
    else if (index == 6){
        endval = "Basic Armor";
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
    if (Item1.getDefName() != "j" || Item1.getAtkName() != "j"){
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
            if (input == 1){
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
            else if (input == 2){
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
            else if (input == 3){
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
