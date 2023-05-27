#include <string>
#include "Transaction.cpp"
#include <iostream>
#include <vector>

using namespace std;

class Block{
    private:
        int index;
        string* prev_hash_code;
        string hash_code;
    public:

    vector<Transaction> transactions;  //vector of transaction of fixed size

    Block() = default;

    Block(int index, vector<Transaction> transactions, string* prev_hash_code){ // [this need to change when Transaction is fully implemented, we are assuming string for simplicity]
        this->index = index;
        this->transactions = std::move(transactions); 
        this->prev_hash_code = prev_hash_code;
        this->hash_code = generate_hash_code();
    }

    string generate_hash_code(){
        string transact;
        for(auto & transaction : transactions){
            transact += transaction.get_data_as_string();
        }
    }

    string get_hash_code(){
        return hash_code;
    }

    string get_prev_hash_code(){
        return (*prev_hash_code);
    }

    bool is_valid(){
        return (hash_code == generate_hash_code());
    }

    void short_display(){
        cout << "       Index:              " << index << endl;
        cout << "       Hash code:          " << hash_code << endl;
        cout << "       Prev. hash code:    " << *prev_hash_code << endl;
    }
};