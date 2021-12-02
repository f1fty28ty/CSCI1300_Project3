#include <iostream>
#include <fstream>
#include <string>
#include "Items.h"


using namespace std;

int split(string original, char delim, string str[], int size){
    // setting evaluation variables
    int stringcompare = original.length();
    int charcounter = 0;
    string compare = "";
    compare += delim;
    int stringpos = 0;
    int endword = 0;
    int startword = 0;
    int possibledelim;
    string arrayvalue;
    for (int i = 0; i < stringcompare; i++) {
        if (original.substr(i,1) == compare) {
            // counting the initial number of delims for a sanity check
            charcounter++;
        }
    }
    if (charcounter >= (size)) {
        // checking if the number of delims is greater than or equal to the number of spots avalible in the array
        // if this condition is met, it separates only the ones that fit in the end array and returns -1
        for (int i = 0; i < stringcompare; i++) {
            if (original.substr(i,1) == compare) {
                endword = i;
                endword = endword - startword;
                arrayvalue = original.substr(startword,endword);
                str[stringpos] = arrayvalue;
                startword = i + 1;
                charcounter++;
                stringpos++;
            }
        }
        return -1;
    }
    if (stringcompare > 0) {
        // the function for a correct case 
        possibledelim = charcounter;
        charcounter = 0;
        for (int i = 0; i < stringcompare; i++) {
            if (original.substr(i,1) == compare) {
                endword = i;
                // the endword is the used as the length of a substr() function 
                endword = endword - startword;
                arrayvalue = original.substr(startword,endword);
                // setting the comparison string to the substring between the delims
                str[stringpos] = arrayvalue;
                startword = i + 1;
                // setting up the startword for the next word as the statement stops at the delim character
                charcounter++;
                // adding delim so that the function knows when the final one occurs
                stringpos++;
                // operator for the end string
                }
            else if (charcounter == possibledelim) {
                // case for when the delim value = the maximum no of delims
                endword = stringcompare;
                endword = endword - startword;
                arrayvalue = original.substr(startword,endword);
                str[stringpos] = arrayvalue;
                // same as above but without counters or resetting startword
            }
            
        }
    }
    else {
        // returning 0 if the original string is 0 characters or below
        return 0;
    }
    // returning the end value to accompany the end string
    return stringpos+1;
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
            newAtk = stoi(atkstat[i]);
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
            newDef = stoi(defstat[i]);
        }
    }
    if (newDef == 0) {
        newDef = 10;
    }
    def = newDef;
}

int Items::getAtkPrice(string itematk){
    if (itematk == "s") {
        return stoi(atkprice[0]);
    }
    else if (itematk == "a") {
        return stoi(atkprice[1]);
    }
    else if (itematk == "b") {
        return stoi(atkprice[2]);
    }
    else if (itematk == "c") {
        return stoi(atkprice[3]);
    }
    else if (itematk == "d") {
        return stoi(atkprice[4]);
    }
    else if (itematk == "f") {
        return stoi(atkprice[5]);
    }
    else {
        return stoi(atkprice[6]);
    }
}

int Items::getDefPrice(string itemdef){
    if (itemdef == "s") {
        return stoi(defprice[0]);
    }
    else if (itemdef == "a"){
        return stoi(defprice[1]);
    }
    else if (itemdef == "b"){
        return stoi(defprice[2]);
    }
    else if (itemdef == "c"){
        return stoi(defprice[3]);
    }
    else if (itemdef == "d"){
        return stoi(defprice[4]);
    }
    else if (itemdef == "f"){
        return stoi(defprice[5]);
    }
    else {
        return stoi(defprice[6]);
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
        split(fileoutput,',',str,5);
        if (i < 6){
            atkstat[i] = str[1];
            atkname[i] = str[0];
            atkprice[i] = str[3];
        }
        else if (i >=6 && i < 12){
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
