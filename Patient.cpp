/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Patient.cpp
 * Author: Huy Khoi Nguyen
 * Student number: 500954699
 * Created on November 4, 2021, 6:03 PM
 */

#include <cstdlib>
#include "Patient.h"
using namespace std;

Patient :: Patient(string name, int cardnumber){
    Name = name;
    CardNumber = cardnumber;
    //initialize the condition and cervix dilation
    Condition = "UNKNOWN";
    CervixDilation = 0;
}
Patient :: ~Patient(){
}
string Patient :: getName(){
    return Name;
}
int Patient :: getCardNumber(){
    return CardNumber;
}
string Patient :: getCondition(){
    return Condition;
}
int Patient :: getCervixDilation(){
    return CervixDilation;
}
int Patient :: setCervixDilation(int cervixdilation){
    CervixDilation = cervixdilation;
}
int Patient :: setCondition(string condition){
    Condition = condition;
}