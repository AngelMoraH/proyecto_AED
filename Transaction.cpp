#include <string>
#include <iostream>

using namespace std;

struct Transaction{
    int index=0;
    //datos de nuestra base de datos

    Transaction(){
        index = 0;
        //datos de nuestra base de datos
    }

    int get_index(){
        return index;
    }

    string get_data_as_string();//retun datos como un unico string

    void transaction_create(int& indice){
        index= indice;
        indice++;
        //obtencion de datos para la transaccion
    }

    void display(){
        //impresion de datos
    }
};