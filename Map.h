#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std; 

class Map
{
     private:
          static const int num_rows = 6;
          static const int num_cols = 10;
          static const int num_Shops = 3;
          static const int num_Levels = 6;

          int playerPosition[2];
          int levelPosition[num_Levels][2];
          int shopPositions[num_Shops][2];
          char mapData[num_rows][num_cols];

          int shop_count;
          int level_count;
          bool level_on_map;

     public :
          Map();

          void resetMap();

          // getters
          int getPlayerRowPosition();
          int getPlayerColPosition();
          int getShopCount();
          int getLevelCount();

          // setters
          void setPlayerRowPosition(int);
          void setPlayerColPosition(int);
          void setShopCount(int);
          void setLevelCount(int);

          bool spawnShop(int, int);
          bool spawnLevel(int, int);

          void displayMap();
          void displayMoves();  
          bool executeMove(char);

          bool isLevelLocation();
          bool isShopLocation();
};
 
#endif
