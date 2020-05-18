#include "IO.h"

using namespace std;

IO::IO() {
    cout << "IO constructor." << endl;
}

void IO::add_line(Line line) {
    lines_.push_back(line);
}

Input::Input() {
    cout << "Input constructor." << endl;
}

void Input::pedir_datos() {
    cout << "Pidiendo datos a usuario." << endl;
}

// TODO: figure out if we should just modify private variable and return void instead.
vector<Line> Output::alter_lines() {
    cout << "Sorteando datos del output." << endl;
    vector<Line> v;
    v.push_back(Line("santi"));
    return v;
}

Output::Output() {
    cout << "Output constructor." << endl;
}

void Output::display_datos() {
    cout << "Displaying datos a usuario." << endl;
}