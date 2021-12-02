#include <iostream>
#include <fstream>
#include <string>
#include "Items.h"


using namespace std;

int split1 (string str, char delim, string tempArr[], int arrSize){
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

Items::Items(){
    statFile = "items.txt";
}

int Items::getAtk(){
    return atk;
}

void Items::setAtk(string itematk){
    int newAtk = 0;
    for (int i = 0; i < 6; i++){
        if (atkname[i] == itematk){
            newAtk = stol(atkstat[i]);
        }
    }
    if (newAtk == 0) {
        newAtk = 10;
    }
    atk = newAtk;
}

int Items::getDef(){
    return def;
}

void Items::setDef(string itemdef){
    int newDef;
    for (int i = 0; i < 6; i++){
        if (defname[i] == itemdef){
            newDef = stol(defstat[i]);
        }
    }
    if (newDef == 0) {
        newDef = 10;
    }
    def = newDef;
}

int Items::getAtkPrice(string itematk){
    if (itematk == "s") {
        return stol(atkprice[0]);
    }
    else if (itematk == "a") {
        return stol(atkprice[1]);
    }
    else if (itematk == "b") {
        return stol(atkprice[2]);
    }
    else if (itematk == "c") {
        return stol(atkprice[3]);
    }
    else if (itematk == "d") {
        return stol(atkprice[4]);
    }
    else if (itematk == "f") {
        return stol(atkprice[5]);
    }
    else {
        return stol(atkprice[6]);
    }
}

int Items::getDefPrice(string itemdef){
    if (itemdef == "s") {
        return stol(defprice[0]);
    }
    else if (itemdef == "a"){
        return stol(defprice[1]);
    }
    else if (itemdef == "b"){
        return stol(defprice[2]);
    }
    else if (itemdef == "c"){
        return stol(defprice[3]);
    }
    else if (itemdef == "d"){
        return stol(defprice[4]);
    }
    else if (itemdef == "f"){
        return stol(defprice[5]);
    }
    else {
        return stol(defprice[6]);
    }
}
string Items::getAtkName(){
    return atkitemname;
}

string Items::getDefName(){
    return defitemname;
}


void Items::setAtkName(int index){
    if (index == 0){
        atkitemname = atkname[6];
    }
    else if (index == 1) {
        atkitemname = atkname[0];
    }
    else if (index == 2){
        atkitemname = atkname[1];
    }
    else if (index == 3){
        atkitemname = atkname[2];
    }
    else if (index == 4){
        atkitemname = atkname[3];
    }
    else if (index == 5){
        atkitemname = atkname[4];
    }
    else if (index == 6){
        atkitemname = atkname[5];
    }
}

void Items::setDefName(int index){
    if (index == 0) {
        defitemname = defname[6];
    }
    else if (index == 1) {
        defitemname = defname[0];
    }
    else if (index == 2){
        defitemname = defname[1];
    }
    else if (index == 3){
        defitemname = defname[2];
    }
    else if (index == 4){
        defitemname = defname[3];
    }
    else if (index == 5){
        defitemname = defname[4];
    }
    else if (index == 6){
        defitemname = defname[5];
    }
}

void Items::populateStats(){
    string fileoutput;
    int i = 0;
    string str[20];
    ifstream in2;
    in2.open(statFile);
    while(getline(in2,fileoutput)){
        split1(fileoutput,',',str,5);
        if (i < 6){
            atkstat[i] = str[1];
            atkname[i] = str[0];
            atkprice[i] = str[3];
        }
        else if (i >=6 ){
            defstat[i-6] = str[2];
            defname[i-6] = str[0];
            defprice[i-6] = str[3];
        }
        i++;
    }
    atkstat[6] = "10";
    atkprice[6] = "0";
    atkname[6] = "j"; 
    defstat[6] = "10";
    defprice[6] = "0";
    defname[6] = "j"; 
}
