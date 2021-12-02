#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//#include "Enemy.h"
//#include "Items.h"
//#include "Level.h"
#include "Map.h"
#include "Player.h"
//#include "Shop.h"

using namespace std;

int split (string str, char delim, string tempArr[], int arrSize);
void printProfile(Player player1);

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
