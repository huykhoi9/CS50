/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OTPRegister.h
 * Author: Huy Khoi Nguyen
 * Student number: 500954699
 * Created on November 4, 2021, 5:26 PM
 */

#ifndef OTPREGISTER_H
#define OTPREGISTER_H
#include <iostream>
#include <deque>
#include "Patient.h"
#include <string>
#include <iomanip> // setw
using namespace std;

class OurPatientPointersQueqe{ 
private: 
    deque < Patient * > q;
public:
    OurPatientPointersQueqe();
    ~OurPatientPointersQueqe();
    void enroll(string, int);
    void examine();
    void display();
    int countPatient();
};

#endif /* OTPREGISTER_H */

