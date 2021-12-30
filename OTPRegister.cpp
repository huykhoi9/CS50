/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OTPRegister.cpp
 * Author: Huy Khoi Nguyen
 * Student number: 500954699
 * Created on November 4, 2021, 5:25 PM
 */
using namespace std;
#include <cstdlib>
#include "OTPRegister.h"
#include "Patient.h"

OurPatientPointersQueqe :: OurPatientPointersQueqe(){
}
OurPatientPointersQueqe :: ~OurPatientPointersQueqe(){
    int qSize = q.size();
    for(int i = 0; i < qSize; i++){
        delete q[i];
        q[i] = 0;
    }
}
void OurPatientPointersQueqe :: enroll(string name, int cardnumber){
    Patient * p = new Patient(name, cardnumber);
    q.push_back(p);
}

void OurPatientPointersQueqe :: examine(){
    if (q.empty()){
        return;
    }
    Patient *p = q[0];
    q.pop_front();
    int cervixdilation = 0;
    
    if(p->getCondition() == "UNKNOWN"){
        
        cout << "Name: " << p->getName() << endl;
        cout << "Health Card Number: " << p->getCardNumber() << endl;
        cout << "Enter Cervix Dilation: ";
        cin >> cervixdilation;
        
        // ask for the input and plug into function setCervixDilattion to determine "ADMIT" or "LABOUR"
        p->setCervixDilation(cervixdilation);
        
        if (p->getCervixDilation() >= 4){
            p->setCondition("ADMIT");
            cout << ".. [Admitting]" << endl;
            cout << p->getName() << "   "
                 << p->getCardNumber() << "   "
                 << p->getCervixDilation() << "   "
                 << p->getCondition() << endl ;
            delete p; p = 0;
        }
        else if (p->getCervixDilation() < 4){
            p->setCondition("LABOUR");
            cout << ".. [Going back to queue]" << endl;
            q.push_back(p);
        }
    }
    else if(p->getCondition() == "LABOUR"){
        
        cout << "Name: " << p->getName() << endl;
        cout << "Health Card Number: " << p->getCardNumber() << endl;
        cout << "Enter Cervix Dilation: ";
        cin >> cervixdilation;
        
        p->setCervixDilation(cervixdilation);
        
        if (p->getCervixDilation() >= 4){
            p->setCondition("ADMIT");
            cout << ".. [Admitting]" << endl;
            cout << p->getName() << "   "
                 << p->getCardNumber() << "   "
                 << p->getCervixDilation() << "   "
                 << p->getCondition() << endl ;
            delete p; p = 0;
        }
        else if(p->getCervixDilation() < 4){
            cout << ".. [Going back to queue]" << endl;
            q.push_back(p);
        }
    }
}

void OurPatientPointersQueqe :: display(){
    int qSize = q.size();
    for (int i = 0; i < qSize; i++){
        cout << left <<setw(10)<<q[i]->getName()
             << left << setw(8)
             << q[i]->getCardNumber()
             << left << setw(8)
             << q[i]->getCervixDilation()
             << left << setw(8)
             << q[i]->getCondition() << endl;           
    }
}

// this function is used to update the number of patients
int OurPatientPointersQueqe :: countPatient(){
    return q.size();
}

