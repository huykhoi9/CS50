/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Patient.h
 * Author: Huy Khoi Nguyen
 * Student number: 500954699
 * Created on November 4, 2021, 5:27 PM
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
using namespace std;

class Patient{
private:
    string Name;
    int CardNumber;
    string Condition; 
    int CervixDilation;
public:
    Patient(string, int); 
    ~Patient();
    string getName();
    int getCardNumber();
    string getCondition();
    int getCervixDilation();
    int setCervixDilation(int);
    int setCondition(string);
};

#endif /* PATIENT_H */

