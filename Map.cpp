#include "Map.h"

using namespace std; 

Map::Map()
{
    resetMap();
}

// resets player position, count values, and initializes values in position arrays to -1
void Map::resetMap() {
    playerPosition[0] = 0; 
    playerPosition[1] = 0;

    shop_count = 0;
    level_count = 0;
    level_on_map = false;

    for (int i = 0; i < num_Shops; i++) {
        shopPositions[i][0] = -1;
        shopPositions[i][1] = -1;
    }
    for (int i = 0; i < num_Levels; i++) {
        levelPosition[i][0] = -1;
        levelPosition[i][1] = -1;
    }
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mapData[i][j] = '-';
        }
    }
}

// return player's row position
int Map::getPlayerRowPosition() {
    return playerPosition[0];
}

// return player's column position
int Map::getPlayerColPosition() {
    return playerPosition[1];
}

int Map::getShopCount() {
    return shop_count;
}

int Map::getLevelCount() {
    return level_count;
}
// set player's row position to parameter row
void Map::setPlayerRowPosition(int row) {
    playerPosition[0] = row;
}

// set player's column position to parameter row
void Map::setPlayerColPosition(int col) {
    playerPosition[1] = col;
}

void Map::setShopCount(int count) {
    shop_count = count;
}

void Map::setLevelCount(int count) {
    level_count = count;
}

/* add NPC to map
 * Parameters: where to spawn NPC -- row (int), col (int)
 * Return: (bool) false if no more space in npcPositions array
 *                      or if (row, col) is an invalid position
 *                      or if (row, col) is already populated; else true
 */
bool Map::spawnShop(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    if (shop_count >= num_Shops) {
        return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (shopPositions[shop_count][0] == -1 && shopPositions[shop_count][1] == -1) {
        shopPositions[shop_count][0] = row;
        shopPositions[shop_count][1] = col;
        mapData[row][col] = 'S';
        shop_count++;
        return true;
    }

    return false;
}

/* add Best Buy to map
 * Parameters: where to spawn Best Buy -- row (int), col (int)
 * Return: (bool) false if (row, col) is an invalid location
 *                      or if (row, col) is already populated
 *                      or if there is a best buy already on the map; else true
 */
bool Map::spawnLevel(int row, int col) {
    // out of map bounds

    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }
    if (level_count >= num_Levels) {
        return false;
    }
    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (levelPosition[level_count][0] == -1 && levelPosition[level_count][1] == -1) {
        levelPosition[level_count][0] = row;
        levelPosition[level_count][1] = col;
        mapData[row][col] = 'L';
        level_count++;
        level_on_map = true;
        return true;
    }

    return false;
}

// return true if x, y position has a best buy there
bool Map::isLevelLocation(){
    for(int i = 0; i < num_Levels; i++){
        if(levelPosition[i][0] == playerPosition[0] && levelPosition[i][1] == playerPosition[1]){
            return true; 
        }
    }
    return false; 
}

// return true if x, y position has an npc there
bool Map::isShopLocation(){
    for(int i = 0; i < num_Shops; i++){
        if(shopPositions[i][0] == playerPosition[0] && shopPositions[i][1] == playerPosition[1]){
            return true; 
        }
    }
    return false; 
}

/*
 * This function prints a menu of valid moves based on playerPosition
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMoves(){
    if(!(playerPosition[0] == 0)){
        cout << "w (Up)" << endl;
    }
    if(!(playerPosition[0] == (num_rows - 1))){
        cout << "s (Down)" << endl; 
    }
    if(!(playerPosition[1] == 0)){
        cout << "a (Left)" << endl; 
    }
    if(!(playerPosition[1] == (num_cols - 1))){
        cout << "d (Right)" << endl; 
    }
}

/*
 * This function takes in user input
 * and updates playerPosition on the map.
 * Parameters: move (char) -- 'w' (up), 'a' (left), 's' (down), 'd' (right)
 * Return: (bool) if move is valid, then true, else false
 */
bool Map::executeMove(char move){
    // if user inputs w, move up if it is an allowed move
    if(!(playerPosition[0] == 0) && (tolower(move) == 'w')){
        playerPosition[0] -= 1;
        return true; 
    }
    // if user inputs s, move down if it is an allowed move
    else if(!(playerPosition[0] == (num_rows - 1))&& (tolower(move) == 's')){
        playerPosition[0] += 1;
        return true; 
    }
    // if user inputs a, move left if it is an allowed move
    else if(!(playerPosition[1] == 0)&& (tolower(move) == 'a')){
        playerPosition[1] -= 1;
        return true; 
    }
    // if user inputs d, move right if it is an allowed move
    else if(!(playerPosition[1] == (num_cols - 1))&& (tolower(move) == 'd')){
        playerPosition[1] += 1;
        return true; 
    }
    else{
        cout << "Invalid Move" << endl; 
        return false; 
    }
}

/*
 * This function prints a 2D map in the terminal.
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (playerPosition[0] == i && playerPosition[1] == j) {
                cout << "x";
            } else if (mapData[i][j] == 'D') {  // don't show hacker on the map
                cout << '-';
            }
            else {
                cout << mapData[i][j];
            }
        }
        cout << endl;
    }
}
