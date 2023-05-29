#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <string>
#include "Block.h"
#include "double.h"

using namespace std;

class Blockchain
{
private:
    List<Block *> *chain = new DoubleList<Block *>();
    unsigned int size_chain = 0;

public:
    // Constructor
    Blockchain() {}

    // Public Functions
    void addBlock(Transaction *data);
    void show_blockchain();
    void test_proof_work(int id);
    void fix_all();
};

void Blockchain::addBlock(Transaction *data)
{
    if (this->chain->back() != nullptr)
    {
        Block *prev_block = this->chain->back();
        Block *new_block = new Block(data);
        string prev_hash = prev_block->get_hash();
        new_block->set_id(this->size_chain + 1, prev_hash);
        new_block->mine();
        this->chain->push_back(new_block);
        this->size_chain = this->chain->size();
    }
    else
    {
        Block *new_block = new Block(data);
        new_block->set_id(this->size_chain + 1, "");
        new_block->mine();
        this->chain->push_back(new_block);
        this->size_chain = this->chain->size();
    }
}

void Blockchain::show_blockchain()
{
    ListIterator<Block *> it;
    for (it = this->chain->begin(); it != this->chain->end(); ++it)
    {
        Block *currentBlock = *it;
        currentBlock->show_block_info();
    }
}

void Blockchain::test_proof_work(int id)
{
    int cont = 1;
    ListIterator<Block *> it;
    string hash_tmp;
    bool flag1 = false;
    bool flag2 = false;
    for (it = this->chain->begin(); it != this->chain->end(); ++it)
    {
        Block *currentBlock = *it;
        if (flag2 == true)
        {
            currentBlock->set_hash_prev(hash_tmp);
            currentBlock->mine();
        }
        if (flag1 == true)
        {
            currentBlock->set_hash_prev(hash_tmp);
        }
        if (cont == id)
        {
            string new_name;
            cout << endl
                 << "Ingrese nombre para el nuevo emisor: ";
            cin >> new_name;
            currentBlock->modify(new_name);
            cout << endl
                 << "Desea arreglar el blockChain? (0 o 1): ";
            bool fix;
            cin >> fix;
            if (fix == false)
            {
                flag1 = true;
            }
            else
            {
                currentBlock->mine();
                flag2 = true;
            }
        }
        hash_tmp = currentBlock->get_hash();
        cont++;
    }
}

void Blockchain::fix_all()
{
    ListIterator<Block *> it;
    string hash_tmp;
    for (it = this->chain->begin(); it != this->chain->end(); ++it)
    {
        Block *currentBlock = *it;
        if (currentBlock->get_validation() == false)
        {
            currentBlock->set_hash_prev(hash_tmp);
            currentBlock->mine();
        }
        hash_tmp = currentBlock->get_hash();
    }
}

#endif
