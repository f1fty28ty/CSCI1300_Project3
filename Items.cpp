#include <iostream>
#include <fstream>
#include <string>
#include "Items.h"

using namespace std;

Items::Items(string newAtkName, string newDefName){
    statFile = "items.txt";
    defName = newDefName;
    atkName = newAtkName;
}

string Items::getAtkName(){
    return atkName;
}

void Items::setAtkName(string newAtkName){
    atkName = newAtkName;
}

int Items::getAtk(){
    return atk;
}

void Items::setAtk(int newAtk){
    atk = newAtk;
}

string Items::getDefName(){
    return defName;
}

void Items::setDefName(string newDefName){
    defName = newDefName;
}

int Items::getDef(){
    return def;
}

void Items::setDef(int newDef){
    def = newDef;
}

void populateStats(string statFile, string atkName, string defName){
    // this function will take the item stat index file and populate the stats array for use by the other functions in the game with the statistics assigned to the different weapons 
    // it will not return any value as hte only purpose of the function is to populate the stats for further use by the setters and getters in this function
    // the function will give individualized stats as input by the name of the defense and attack items
}