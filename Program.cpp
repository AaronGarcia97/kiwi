#include "Program.h"

using namespace std;

Program::Program() {
    cout << "New Program created." << endl;
    input_ = Input();
    output_ = Output();
    processor_context_ = ProcessorContext();
}

void Program::start() {
    cout << "[+] Starting program." << endl;
    input_.pedir_datos();
    processor_context_.set_processor_strategy(new ShiftStrategy());
}

void Program::process() {
    cout << "[+] Processing program." << endl;
    output_ = processor_context_.processor_strategy()->process(input_);
}

void Program::display() {
    cout << "[+] Displaying program." << endl;
    output_.set_is_ascendente(input_.is_ascendente());
    output_.alter_lines();
    output_.display_datos_debug(output_.lines());
    output_.display_datos();
}