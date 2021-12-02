#include "Shop.h"

using namespace std;

int Shop::getBalance(){
    return newPlayerMoney;
}

void Shop::setBalance(int playerMoney){
    newPlayerMoney = playerMoney;
}
