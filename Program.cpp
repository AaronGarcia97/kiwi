#include "Program.h"

using namespace std;

Program::Program() {
    cout << "New Program created." << endl;
    input_ = Input();
    output_ = Output();
    processor_context_ = ProcessorContext();
}

void Program::start() {
    cout << "Started program." << endl;
    input_.pedir_datos();
}

void Program::process() {
    cout << "Processed program." << endl;
}

void Program::display() {
    cout << "Displayed program." << endl;
}