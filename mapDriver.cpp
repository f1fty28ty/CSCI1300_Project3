#include <iostream>
#include "Map.h"
#include "Enemy.h"
#include "Level.h"

using namespace std; 

int main() {
    Map map;  // create object called map of type Map
    map.spawnLevel(1, 2);
    map.spawnLevel(1, 5);
    map.spawnLevel(1, 8);
    map.spawnLevel(4, 2);
    map.spawnLevel(4, 5);
    map.spawnLevel(4, 8);
    map.spawnShop(2, 5);
    map.spawnShop(3, 5);

    char move;  // for storing user input
    int userInput;
    int level;

    // quit after 10 moves
    for(int i = 0; i < 10; i++) {
        cout << "Levels from L-R" << endl;
        cout << "0 1 2" << endl;
        cout << "3 4 5" << endl;
        map.displayMap();  // pretty print map_data in terminal

        cout << "Valid moves are: " << endl; 
        map.displayMoves();  // give user a menu of valid moves to pick from
        
        cout << "Input a move: "; 
        cin >> move;
        cout << endl;
        map.executeMove(move);  // move the player on map based on user input

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
