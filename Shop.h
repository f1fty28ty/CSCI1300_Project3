
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Shop{

    public:
    int getBalance();
    void setBalance(int playerMoney);

    private:
    int playerMoney;
    int newPlayerMoney;
};
