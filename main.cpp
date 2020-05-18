#include <iostream>

#include "Program.h"

using namespace std;

int main(int argv, char** args) {

    Program santiago = Program();
    santiago.start();
    santiago.process();
    santiago.display();

    return 0;
}

