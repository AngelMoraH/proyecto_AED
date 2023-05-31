#include "menu.h"

using namespace std;
void Menu(Blockchain *block_coin);

int main()
{
    Blockchain *block_coin = new Blockchain();
    Menu(block_coin);

    return 0;
}
