/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lab5Main.cpp
 * Author: Huy Khoi Nguyen
 * Student number: 500954699
 * Created on November 4, 2021, 6:04 PM
 */

#include <iostream>
#include <cstdlib>
#include "OTPRegister.h"

using namespace std;

void updatePatients(int num);
string name;
int cardnumber;
OurPatientPointersQueqe thePatient;

int main(int argc, char** argv) {
    // to update the patient in the list
    int count = 0;
    
    while(1){
        updatePatients(count);
        cout <<"Please choose an option:" <<endl
             << "1. Register Patient" << endl
             << "2. Examine Patient" << endl
             << "3. Display Patients" << endl
             << "4. Quit" << endl
             << ">> ";
        int num = 0;
        cin >> num;

        //switch for user input 1-4
        switch(num){
            case 1:
                cout << "=============" << endl;
                cout << "[Register Patient]" << endl;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Health Care Number: ";
                cin >> cardnumber;
             
                thePatient.enroll(name, cardnumber);
                
                cout << ".. [Registering]" << endl << endl;
                count++;
                break;
                
            case 2:
                cout << "=============" << endl
                     << "[Examine Patient]" << endl;
                thePatient.examine();
                cout << endl;
                // use function in class OTPRegister to update the number of patients 
                count = thePatient.countPatient();
                break;
                
            case 3:
                cout << "=============" << endl
                     << "[Display Patients]" << endl;
                thePatient.display();
                cout << endl;
                break;
                
            case 4:
                return 0;
        }
    }
}

// Update the number of patients stored in the struct
void updatePatients(int num){
    cout << "=======================" << endl;
    cout << "There are currently " << num << " patient(s) in the list" << endl << endl;
}
