#include <iostream>
#include "Shop.h"
#include <fstream>
#include <string>

using namespace std;

Shop::Shop(int newPlayerMoney){
    shopFile = "shop.txt";
    itemFile = "item.txt";
    playerMoney = newPlayerMoney;
}

int Shop::getBalance(){
    return playerMoney;
}

void Shop::setBalance(int newPlayerMoney){
    playerMoney = newPlayerMoney;
}

int Shop::getPrice(){
    return itemPrice;
}

void Shop::setPrice(int newPrice){
    itemPrice = newPrice;
}

string Shop::getItemName(){
    return itemName;
}

void Shop::setItemName(string newItem){
    itemName = newItem;
}
/*
bool Shop::itemBought(string itemName){
    //this function will check if items are bought in the shop and return different values depending on if it's bought or not
    //if an item is already bought it will replace the option to buy said item with an "already purchased" label
    //this is to prevent an item from being purchased infinite times
}
*/
void Shop::populateInventory(string shopFile){
    // this function will read the set shop file and construct the storefront using the info from said file
}
/*
int printShop(string shopInventory[]){
    // this function will take the constructed array from shopInventory and print them to the user for viewing. 
    // it will utilize switch statements to access different gear types, like armor, weapons, general item
    // this function will also allow the user to select an item to buy, calling the appropriate functions to set the balance accordingly
    // it will return the balance post-purchase
}
*/
