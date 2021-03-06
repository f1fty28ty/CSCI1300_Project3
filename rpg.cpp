//Miles Silveria && Evan Zachary
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

#include "Enemy.h"
#include "Items.h"
#include "Level.h"
#include "Map.h"
#include "Player.h"


using namespace std;
//Miles Silveria
int split (string str, char delim, string tempArr[], int arrSize);
void printProfile(Player player1);
void adv(Player &player1, Enemy enemys[]);
//Evan Zachary
int printShop(Items &Item1, Player &player1);
string typeConverter(int index);
string CharConverter(char val);
char StringConverter(string nameval);
int reverseConverter(string inputstring);
int purchaseSwords(int money, Items &Item1);
string atkItemName(int index);
int purchaseArmor(int money, Items &Item1);
int sellItems(int money, Items &Item1);
int buyPotions(int money, Player &player1);
string defItemName(int index);
void boss(Player &player1, Items &Item1);

int main(){
    time_t lvlstart;
    time_t lvlend;
    double lvltimes[6];
    //sets item
    Items Item1;
    Item1.populateStats();
    //setting stuff for player
    //checks if there is a previous player on file
    //Will always play on that save for convenience
    Player player1 = Player();
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
    Enemy enemys[4];
    Level levels[6];
    string levelfileArr[7];
    ifstream lvlFile;
    lvlFile.open("levels.txt");
    int numMobs;
    int dif;
    //sorter vars
    int runSorter = 1;
    double sorterTemp;
    double backupArr[6];
    for(int i = 0; i < 6; i++){
        switch(i){
            case 0:
            getline(lvlFile,line);
            levels[i] = Level();
            break;
            case 1:
            getline(lvlFile,line);
            split(line, ',', levelfileArr, 7);
            numMobs = stoi(levelfileArr[1]);
            dif = stoi(levelfileArr[2]);
            enemys[0].setName(levelfileArr[3]);
            enemys[1].setName(levelfileArr[4]);
            enemys[2].setName(levelfileArr[5]);
            enemys[3].setName(levelfileArr[6]);
            levels[i] = Level(levelfileArr[0], numMobs, enemys, dif);
            break;
            case 2:
            getline(lvlFile,line);
            split(line, ',', levelfileArr, 7);
            numMobs = stoi(levelfileArr[1]);
            dif = stoi(levelfileArr[2]);
            enemys[0].setName(levelfileArr[3]);
            enemys[1].setName(levelfileArr[4]);
            enemys[2].setName(levelfileArr[5]);
            enemys[3].setName(levelfileArr[6]);
            levels[i] = Level(levelfileArr[0], numMobs, enemys, dif);
            break;
            case 3:
            getline(lvlFile,line);
            split(line, ',', levelfileArr, 7);
            numMobs = stoi(levelfileArr[1]);
            dif = stoi(levelfileArr[2]);
            enemys[0].setName(levelfileArr[3]);
            enemys[1].setName(levelfileArr[4]);
            enemys[2].setName(levelfileArr[5]);
            enemys[3].setName(levelfileArr[6]);
            levels[i] = Level(levelfileArr[0], numMobs, enemys, dif);
            break;
            case 4:
            getline(lvlFile,line);
            split(line, ',', levelfileArr, 7);
            numMobs = stoi(levelfileArr[1]);
            dif = stoi(levelfileArr[2]);
            enemys[0].setName(levelfileArr[3]);
            enemys[1].setName(levelfileArr[4]);
            enemys[2].setName(levelfileArr[5]);
            enemys[3].setName(levelfileArr[6]);
            levels[i] = Level(levelfileArr[0], numMobs, enemys, dif);
            break;
            case 5:
            getline(lvlFile,line);
            split(line, ',', levelfileArr, 7);
            numMobs = stoi(levelfileArr[1]);
            dif = stoi(levelfileArr[2]);
            enemys[0].setName(levelfileArr[3]);
            enemys[1].setName(levelfileArr[4]);
            enemys[2].setName(levelfileArr[5]);
            enemys[3].setName(levelfileArr[6]);
            levels[i] = Level(levelfileArr[0], numMobs, enemys, dif);
            break;
        }
    }
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
            cout << "Time Spent in lvls" << endl;
            for(int i = 0; i < 6; i++){
                backupArr[i] = lvltimes[i];
            }
            for(int i = 0; i < 6; i++){
                for(int j = i+1; j < 6; j++){
                    if(lvltimes[j] < lvltimes[i]){
                        sorterTemp = lvltimes[i];
                        lvltimes[i] = lvltimes[j];
                        lvltimes[j] = sorterTemp;
                    }
                }
            }
            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 6; j++){
                    if(lvltimes[i] == backupArr[j]){
                        cout << "Level " << j << ": " << lvltimes[j] << "ms" << endl;
                    }
                }
            }
            cout << "Adios Amigo!!" << endl;
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
            if(map.getPlayerColPosition() == 2 && map.getPlayerRowPosition() == 1){
                level = 0;
                cout << "-You arrive at the clearings of a forest. A man comes up to you.- \n Man: You look like a fresh Adventurer. There seems to be a slime problem. \n Man: I've heard they give a good source of money and xp for you to lvl up." << endl;
            }
            if(map.getPlayerColPosition() == 5 && map.getPlayerRowPosition() == 1){
                level = 1;
                cout << "-You venture to a nearby town. You over hear from the Guild that Wolfs, Zombies, Rats, and Red Necks live near this area.- \n -We should get some good rewards from them.-" << endl;
            }
            if(map.getPlayerColPosition() == 8 && map.getPlayerRowPosition() == 1){
                level = 2;
                cout << "-You over hear screams for help from the nearby village.- \n Villager: Please help us. The Elder Dragon's legion of goblins to come invade." << endl;
            }
            if(map.getPlayerColPosition() == 2 && map.getPlayerRowPosition() == 4){
                level = 3;
                cout << "-As you travel along the road to the Elder Dragon's lair- \n -You are suddenly swarmed by bandits.-" << endl;
            }
            if(map.getPlayerColPosition() == 5 && map.getPlayerRowPosition() == 4){
                level = 4;
                cout << "-You have traveled one step closer to the Elder Dragon's Lair- \n -But first we must deal with his Spawn-" << endl;
            }
            if(map.getPlayerColPosition() == 8 && map.getPlayerRowPosition() == 4){
                level = 5;
                cout << "-You have arrived at the Elder Dragon's front door.-" << endl;
            }
            cout << "Level: " << level << endl;
            if(userInput == 1){
                while(userInput != 0){
                    lvlstart = time(nullptr);
                    cout << "===What would you like to do===" << endl;
                    cout << "1: Adventure" << endl;
                    cout << "2: Heal" << endl;
                    cout << "3: Print Profile" << endl;
                    cout << "0: Leave" << endl;
                    cin >> userInput;
                    if(userInput == 1){
                        switch(level){
                            case 0:
                                levels[0].setEnemys(enemys);
                                adv(player1, enemys);
                            break;
                            case 1:
                                levels[1].setEnemys(enemys);
                                adv(player1, enemys);
                            break;
                            case 2:
                                levels[2].setEnemys(enemys);
                                adv(player1, enemys);
                            break;
                            case 3:
                                levels[3].setEnemys(enemys);
                                adv(player1, enemys);
                            break;
                            case 4:
                                levels[4].setEnemys(enemys);
                                adv(player1, enemys);
                            break;
                            case 5:
                                 boss(player1, Item1);
                            break;
                        }
                    }
                    if(userInput == 2){
                        player1.heal();
                        cout << "You have been healed" << endl;
                    }
                    if(userInput == 3){
                        printProfile(player1);
                    }
                    if(userInput == 0){
                        lvlend = time(nullptr);
                        lvltimes[level] += difftime(lvlend, lvlstart);
                        userInput = 1;
                        break;
                    }
                }
            }else if(userInput == 0){
                userInput = 1;
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
                player1.setMoney(printShop(Item1, player1));
            }else if(userInput == 0){
                userInput = 1;
                cout << "Alright, Back to Map" << endl;
            }else{
                cout << "Invalid Input, Back to Map" << endl;
            }

        }
    }

}
void adv(Player &player1, Enemy enemys[]){
    srand(time(NULL));
    int ran = (rand() % 4) + 0;
    int halfMobXP = enemys[ran].getXp();
    int halfMobMoney = enemys[ran].getMoney();
    int playerHealth = player1.getCurrentHealth();
    int playerDef = player1.getDef();
    int playerDmg = player1.getDmg();
    int playerXp = player1.getCurrentExp();
    int playerMoney = player1.getMoney();
    int mobDmg = enemys[ran].getDmg();
    string mobName = enemys[ran].getName();
    int mobXp = (rand() % enemys[ran].getXp()) + halfMobXP;
    int mobMoney = (rand() % enemys[ran].getMoney()) + halfMobMoney;
    if((playerDef <= mobDmg && playerDmg >= mobDmg) && (playerHealth -= mobDmg) > 0){
        playerHealth -= (mobDmg - (playerDmg / 2));
        cout << player1.getName() << " Has Defeated a(n) " << mobName << "!" << endl;
        cout << player1.getName() << " got +" << mobXp << "XP and +" << mobMoney << " coins!" << endl;
        cout << "HP left " << playerHealth << "/" << player1.getMaxHealth() << endl;
        player1.addExp(mobXp);
        playerMoney += mobMoney;
        player1.setMoney(playerMoney);
        player1.setCurrentHealth(playerHealth);
    }else if(playerDef > mobDmg){
        cout << player1.getName() << " Has Defeated a(n) " << mobName << "!" << endl;
        cout << player1.getName() << " got +" << mobXp << "XP and +" << mobMoney << " coins!" << endl;
        cout << "HP left " << playerHealth << "/" << player1.getMaxHealth() << endl;
        player1.addExp(mobXp);
        playerMoney += mobMoney;
        player1.setMoney(playerMoney);
    }else if((playerHealth -= mobDmg) <= 0){
        cout << player1.getName() << "has died and lost some Money" << endl;
        player1.setMoney(player1.getMoney() - 150);
    }else{
        playerHealth -= (mobDmg - (playerDmg / 2));
        cout << player1.getName() << " Has Defeated a(n) " << mobName << "!" << endl;
        cout << player1.getName() << " got +" << mobXp << "XP and +" << mobMoney << " coins!" << endl;
        cout << "HP left " << playerHealth << "/" << player1.getMaxHealth() << endl;
        player1.addExp(mobXp);
        playerMoney += mobMoney;
        player1.setMoney(playerMoney); 
        player1.setCurrentHealth(playerHealth);
    }
    
}

void boss(Player &player1, Items &Item1){
    srand(time(NULL));
    double ran;
    double crit;
    int numpot = player1.getPotions();
    double playerHealth = player1.getCurrentHealth();
    double playerDef = player1.getDef();
    int playerDmg = player1.getDmg();
    int playerXp = player1.getCurrentExp();
    int playerMoney = player1.getMoney();
    double bosshealth = 10000;
    int bossalive = 0;
    int menuop = 0;
    double dmgreduc;
    int potused = 0;
    int dmglowerbound = 1*(playerDmg/2);
    int dmgupperbound = 3*(playerDmg/2);
    dmgupperbound = dmgupperbound - dmglowerbound;
    if (playerDef >= 100 && Item1.getAtkName() != "j"){
        dmgreduc = 0.75-(playerDef/1000);
    }
    else if (Item1.getAtkName() != "j" && playerDef < 100) {
        dmgreduc = 0.75-(playerDef/100);
    }
    else {
        dmgreduc = 1;
    }
    cout << "You have entered a fight against the Elder Dragon." << endl;
    cout << "\n";
    while (bossalive == 0){
        ran = (rand() % 30) + 60;
        crit = (rand() % dmgupperbound) + dmglowerbound;
        cout << "Current Player Health: " << playerHealth << endl;
        cout << "\n";
        cout << "Current Boss Health: " << bosshealth << endl;
        cout << "\n";
        cout << "What would you like to do?" << endl;
        cout << "\n";
        cout << "1. Swing your sword." << endl;
        cout << "2. Try your luck with a critical attack." << endl;
        if (numpot > 0){
            cout << "3. Heal yourself with a potion" << endl;
        }
        else {
            cout << "3. You have no potions to heal with. Selecting this will result in a loss of turn." << endl;
        }
        cin >> menuop;
        switch (menuop){
            case 1:
            bosshealth -= playerDmg;
            cout << "You damaged the boss for " << playerDmg << " Health" << endl;
            playerHealth -= (ran * dmgreduc);
            break;
            case 2:
            cout << crit << endl;
            if (crit < player1.getDmg()){
                cout << "You swung and missed, leaving yourself wide open." << endl;
            }
            else {
                bosshealth -= crit;
                cout << "You swing and hit the boss for " << crit << " health!" << endl;
            }
            playerHealth -= (ran * dmgreduc);
            break;
            case 3:
            if (numpot > 0){
                playerHealth += 120;
                numpot --;
                potused++;
            }
            playerHealth -= (ran * dmgreduc);
            break;
            default:
            cout << "You didn't know what to do and lost your turn." << endl;
        }
        cout << "The boss did " << (ran * dmgreduc) << " damage to you that turn." << endl;
        if (bosshealth <= 0){
            bossalive = 1;
            cout << "Congratulations on beating the boss!" << endl;
            player1.addExp(10000000);
            player1.setMoney(player1.getMoney()+100000000);
        }
        else if (playerHealth <= 0){
            cout << "You unfortunately perished during the fight with the boss." << endl;
            bossalive = 1;
            player1.setMoney(player1.getMoney() - 150);
        }
        player1.setPotions(player1.getPotions()-potused);
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

int printShop(Items &Item1, Player &player1){
    int money = player1.getMoney();
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
            money = purchaseSwords(money, Item1);
            break;
            case 2: 
            money = purchaseArmor(money, Item1);
            break;
            case 3: 
            money = sellItems(money, Item1);
            break;
            case 4: 
            money = buyPotions(money, player1);
            break;
            case 5:
            cout << "Good Luck on your travels!" << endl;
            cout << "\n";
            whileop = 0;
            break;
            default:
            cout << "That input isn't recognized. Please enter an option between 1 and 5" << endl;
            cout << "\n";
            break;
        }
    }
    player1.setDmg(Item1.getAtk());
    player1.setDef(Item1.getDef());
    player1.setSword(StringConverter(Item1.getAtkName()));
    player1.setArmor(StringConverter(Item1.getDefName()));
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

int purchaseSwords(int money, Items &Item1){
    int value;
    char buy;
    int price1;
    cout << "Your current balance: " << money << endl;
    cout << "\n";
    cout << "Swords for purchase" << endl;
    for (int i = 1; i < 7; i++){
        price1 = Item1.getAtkPrice(typeConverter(i));
        Item1.setAtk(typeConverter(i));
        cout << "Item " << i << ": " << atkItemName(i) << " :: " << price1 << " Coins" <<  endl;
        cout << "Item " << i << " Stats: " << Item1.getAtk() << " Attack " << endl;
        cout << "\n";
    }
    cout << "Which sword would you like to buy?" << endl;
    cin >> value;
    if (Item1.getAtkName() != "j" && Item1.getDefPrice(typeConverter(value)) < money && value > 0 && value < 7){
        price1 = Item1.getAtkPrice(Item1.getAtkName());
        cout << "You must sell your currently equipped sword before purchasing a new one" << endl;
        cout << "Would you like to proceed?" << endl;
        cout << "[Y] [N]" << endl;
        cin >> buy;
        if (buy == 'y' || buy == 'Y') {
            money += price1;
            money -= Item1.getAtkPrice(typeConverter(value));
            Item1.setAtk(typeConverter(value));
            Item1.setAtkName(value);
        }
        else {
            cout << "Transaction not completed. Please try again if this was a mistake." << endl;
        }
    }
    else if (Item1.getAtkPrice(typeConverter(value)) < money && value > 0 && value < 7){
        cout << "Would you like to purchase sword " << value << "?" << endl;
        cout << "[Y] [N]" << endl;
        cin >> buy;
        if (buy == 'y' || buy == 'Y') {
            Item1.setAtkName(value);
            money -= Item1.getAtkPrice(typeConverter(value));
            Item1.setAtk(typeConverter(value));
        }
        else {
            cout << "Transaction not completed. Please try again if this was a mistake." << endl;
        }
    }
    else {
        cout << "You either do not have enough money to purchase this item or entered an invalid item number." << endl;
        cout << "Please try again if this was a mistake." << endl;
        cout << "\n";
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

int purchaseArmor(int money, Items &Item1){
    int value;
    char buy;
    int price1;
    cout << "Your current balance: " << money << endl;
    cout << "\n";
    cout << "Armor sets for purchase" << endl;
    for (int i = 1; i < 7; i++){
        price1 = Item1.getDefPrice(typeConverter(i));
        Item1.setDef(typeConverter(i));
        cout << "Item " << (i) << ": " << defItemName(i) << " :: " << price1 << " Coins" <<  endl;
        cout << "Item " << (i) << " Stats: " << Item1.getDef() << " Attack " << endl;
        cout << "\n";
    }
    cout << "Which armor set would you like to buy?" << endl;
    cin >> value;
    if (Item1.getDefName() != "j" && Item1.getDefPrice(typeConverter(value)) < money && value > 0 && value < 7){
        price1 = Item1.getDefPrice(Item1.getDefName());
        cout << "You must sell your currently equipped armor set before purchasing a new one" << endl;
        cout << "Would you like to proceed?" << endl;
        cout << "[Y] [N]" << endl;
        cin >> buy;
        if (buy == 'y' || buy == 'Y') {
            money += price1;
            money -= Item1.getDefPrice(typeConverter(value));
            Item1.setDef(typeConverter(value));
            Item1.setDefName(value);
        }
        else {
            cout << "Transaction not completed. Please try again if this was a mistake." << endl;
        }
    }
    else if (Item1.getDefPrice(typeConverter(value)) < money && value > 0 && value < 7){
        cout << "Would you like to purchase armor set " << value << "?" << endl;
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
    else {
        cout << "You either do not have enough money to purchase this item or entered an invalid item number." << endl;
        cout << "Please try again if this was a mistake." << endl;
        cout << "\n";
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

int sellItems(int money, Items &Item1){
    char sell;
    int price1;
    int price2;
    int input;
    // ask for input from miles on how inventory is checked
    if (Item1.getDefName() != "j" || Item1.getAtkName() != "j"){
        cout << "Which item would you like to sell?" << endl;
        if (Item1.getAtkName() == "j" && Item1.getDefName() != "j"){
            price1 = Item1.getDefPrice(Item1.getDefName());
            cout << "Armor: " << defItemName(reverseConverter(Item1.getDefName())) << " :: " << price1 << " coins" << endl;
            cout << "You have no sword to sell." << endl;
            cout << "Sell this item?" << endl;
            cout << "[Y] [N]" << endl;
            cin >> sell;
            if (sell == 'y' || sell == 'Y') {
                Item1.getDefPrice(Item1.getDefName());
                Item1.setDefName(0);
                Item1.setDef("j");
                money += price1;
                cout << "\n";
                cout << "Your current balance: " << money << endl;
                cout << "\n";
                cout << "You no longer have any armor equipped. You should consider purchasing some before you leave the shop." << endl;
            }
            else {
                cout << "Transaction not completed. Please try again if this was a mistake." << endl;
            }
        }
        else if (Item1.getDefName() == "j" && Item1.getAtkName() != "j"){
            price1 = Item1.getAtkPrice(Item1.getAtkName());
            cout << "You have no armor to sell." << endl;
            cout << "Sword: " << atkItemName(reverseConverter(Item1.getAtkName())) << " :: " << price1 << " coins" << endl;
            cout << "\n";
            cout << "Sell this item?" << endl;
            cout << "[Y] [N]" << endl;
            cin >> sell;
            if (sell == 'y' || sell == 'Y') {
                Item1.getAtkPrice(Item1.getAtkName());
                Item1.setAtkName(0);
                Item1.setAtk("j");
                money += price1;
                cout << "\n";
                cout << "Your current balance: " << money << endl;
                cout << "\n";
                cout << "You no longer have a sword equipped. You should consider purchasing one before you leave the shop." << endl;
            }
            else {
                cout << "Transaction not completed. Please try again if this was a mistake." << endl;
            }
        }
        else {
            price1 = Item1.getDefPrice(Item1.getDefName());
            cout << "Armor: " << defItemName(reverseConverter(Item1.getDefName())) << " :: " << price1 << " coins" << endl;
            price2 = Item1.getAtkPrice(Item1.getAtkName());
            cout << "Sword: " << atkItemName(reverseConverter(Item1.getAtkName())) << " :: " << price2 << " coins" << endl;
            cout << "\n";
            cout << "Which of these items would you like to sell?" << endl;
            cout << "1. Sword    2. Armor     3. Both" << endl;
            cin >> input;
            if (input == 1){
                price1 = Item1.getAtkPrice(Item1.getAtkName());
                cout << "Sword: " << atkItemName(reverseConverter(Item1.getAtkName())) << " :: " << price1 << " coins" << endl;
                cout << "\n";
                cout << "Sell this item?" << endl;
                cout << "[Y] [N]" << endl;
                cin >> sell;
                if (sell == 'y' || sell == 'Y') {
                    Item1.getAtkPrice(Item1.getAtkName());
                    Item1.setAtkName(0);
                    Item1.setAtk("j");
                    money += price1;
                    cout << "\n";
                    cout << "Your current balance: " << money << endl;
                    cout << "\n";
                    cout << "You no longer have a sword equipped. You should consider purchasing one before you leave the shop." << endl;
            }
            else {
                cout << "Transaction not completed. Please try again if this was a mistake." << endl;
            }
            }
            else if (input == 2){
                price1 = Item1.getDefPrice(Item1.getDefName());
                cout << "Armor: " << defItemName(reverseConverter(Item1.getDefName())) << " :: " << price1 << " coins" << endl;
                cout << "Sell this item?" << endl;
                cout << "[Y] [N]" << endl;
                cin >> sell;
                if (sell == 'y' || sell == 'Y') {
                    Item1.getDefPrice(Item1.getDefName());
                    Item1.setDefName(0);
                    Item1.setDef("j");
                    money += price1;
                    cout << "\n";
                    cout << "Your current balance: " << money << endl;
                    cout << "\n";
                    cout << "You no longer have any armor equipped. You should consider purchasing some before you leave the shop." << endl;
                }
                else {
                    cout << "Transaction not completed. Please try again if this was a mistake." << endl;
                }
            }
            else if (input == 3){
                price1 = Item1.getAtkPrice(Item1.getAtkName());
                cout << "Sword: " << atkItemName(reverseConverter(Item1.getAtkName())) << " :: " << price1 << " coins" << endl;
                price2 = Item1.getDefPrice(Item1.getDefName());
                cout << "Armor: " << defItemName(reverseConverter(Item1.getDefName())) << " :: " << price2 << " coins" << endl;
                cout << "Sell these items?" << endl;
                cout << "[Y] [N]" << endl;
                cin >> sell;
                if (sell == 'y' || sell == 'Y') {
                    Item1.getAtkPrice(Item1.getAtkName());
                    Item1.setAtkName(0);
                    Item1.setAtk("j");
                    money += price1;
                    Item1.getDefPrice(Item1.getDefName());
                    Item1.setDefName(0);
                    Item1.setDef("j");
                    money += price2;
                    cout << "\n";
                    cout << "Your current balance: " << money << endl;
                    cout << "\n";
                    cout << "You no longer any gear equipped. You should consider purchasing more gear before you leave the shop." << endl;
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
    cout << "\n";
    return money;
}

int buyPotions(int money, Player &player1){
    int numpot;
    int existpot;
    char sell;
    int totalpot;
    if (player1.getPotions() == 0){
        cout << "You do not currently have any potions." << endl;
        cout << "Potions are 20 coins each and you currently have " << money << " coins." << endl;
        cout << "How many would you like to purchase?" << endl;
        cin >> numpot;
        if (numpot >= 0 && (numpot * 20 < money)){
            cout << "Do you want to purchase " << numpot << " potions?" << endl;
            cout << "[Y] [N]" << endl;
                cin >> sell;
                if (sell == 'y' || sell == 'Y') {
                    player1.setPotions(numpot);
                    money -= (numpot * 20);
                    cout << "\n";
                    cout << "Your current balance: " << money << endl;
                    cout << "\n";
                }
                else {
                    cout << "Transaction not completed. Please try again if this was a mistake." << endl;
                }
        }
        else {
            cout << "Transaction not completed. Please try again if this was a mistake." << endl;
        }

    }
    else {
        existpot = player1.getPotions();
        cout << "Potions are 20 coins each." << endl; 
        cout << "You currently have " << money << " coins and " << existpot << " potions" << endl;
        cout << "How many would you like to purchase?" << endl;
        cin >> numpot;
        if (numpot >= 0 && (numpot * 20 < money)){
            cout << "Do you want to purchase " << numpot << " potions?" << endl;
            cout << "[Y] [N]" << endl;
                cin >> sell;
                if (sell == 'y' || sell == 'Y') {
                    player1.setPotions(numpot);
                    totalpot = numpot + existpot;
                    player1.setPotions(totalpot);
                    money -= (numpot * 20);
                    cout << "\n";
                    cout << "Your current balance: " << money << endl;
                    cout << "\n";
                }
                else {
                    cout << "Transaction not completed. Please try again if this was a mistake." << endl;
                }
        }
        else {
            cout << "Transaction not completed. Please try again if this was a mistake." << endl;
        }
    }
    return money;
}
