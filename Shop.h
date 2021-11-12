#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Shop{

    public:
    Shop(int newPlayerMoney);
    int getBalance();
    void setBalance(int newBalance);
    int getPrice();
    void setPrice(int newPrice);
    string getItemName();
    void setItemName(string newName);
    //bool itemBought(string itemName);
    void populateInventory(string shopFile);
    //int printMenu(string shopInventory[], int playerMoney);


    private:
    int itemPrice;
    int playerMoney;
    int newPlayerMoney;
    string shopFile;
    string itemFile;
    string itemName;
    string newItem;
    //string shopInventory[placeholder];
};
