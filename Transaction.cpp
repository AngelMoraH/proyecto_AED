#include <string>
#include <ctime>
#include <iostream>

using namespace std;

struct Transaction{
    string index;
    //Informacion de la transaccion
    string senderKey;
    string recieverKey; 
    string time;

    Transaction(double val, string sender, string reciever, time_t time){
        index = to_string(val);
        senderKey = sender;
        recieverKey = reciever;
        this->time = ctime(&time); 
    }

    string get_data_as_string(){ //retun datos como un unico string
        string result = ""; 
        result = (this->index + this->senderKey + this->recieverKey + this->time ); 
        return result; 
    }
    
    void display(){
        //impresion de datos
        cout << "index: " << index << endl;
        cout << "senderkeyy: " << senderKey << endl;
        cout << "recieverkey: " << recieverKey << endl;
        cout << "time: " << time << endl;
    }
};  