#include "IO.h"

using namespace std;

IO::IO() {
    cout << "IO constructor." << endl;
}

void IO::add_line(Line line) {
    lines_.push_back(line);
}

void IO::display_datos() {
    for(auto& line : lines_)
        line.display();
}

vector<vector <string> > IO::vector_string_lines() {
    vector<vector <string> > v;
    for(auto& line : lines_){
        v.push_back(line.object());
    }
    return v;
}

// INPUT methods
Input::Input() {
    cout << "Input constructor." << endl;
}

string clean_input_string(string str) {
    // remove " and . and make it lower case.
    string trimmed_str = str.substr(1, str.length()-3);
    transform(trimmed_str.begin(), trimmed_str.end(), trimmed_str.begin(), ::tolower);
    return trimmed_str;
}

// reads data from file
vector<Line> leer_datos() {
    string string_line;
    vector<Line> v;
    while (getline(cin, string_line)) {
        string trimmed_line = clean_input_string(string_line);
        Line line = Line(trimmed_line, Line::convert_to_vector(trimmed_line));
        v.push_back(line);
    }
    return v;
}

void Input::pedir_datos() {
    cout << "Pidiendo datos a usuario." << endl;
    lines_ = leer_datos();
    cout << "Lineas leidas: " << endl;
    display_datos();
}

Output::Output() {
    cout << "Output constructor." << endl;
}

Output::Output(vector<Line> lines) {
    cout << "Output receiving vector<Line> constructor." << endl;
    lines_ = lines;
}

// lexicogrphical comparator
//(Hotfix): Instead of adding const to each parameter,const at the end tells the
// the compiler explicitly that this funtion doesn't modify any member.
struct less_than_line {
    inline bool operator() (Line& line1, Line& line2) const {
            return 
                lexicographical_compare(
                    line1.original_string().begin(),
                    line1.original_string().end(),
                    line2.original_string().begin(),
                    line2.original_string().end());
    }
};

// TODO: figure out if we should just modify private variable and return void instead.
void Output::alter_lines() {
    cout << "Sorteando datos del output." << endl;
    modified_lines_ = lines_;
    sort(modified_lines_.begin(), modified_lines_.end(), less_than_line());
}

// Displays modified lines
void Output::display_datos_debug() {
    for(auto& line : modified_lines_)
        line.display();    
}

void Output::display_datos() {
    cout << "---------EXPECTED OUTPUT---------" << endl;
    for(auto& line : modified_lines_)
        cout << line.original_string() << endl;
    cout << "-----------END OUTPUT------------" << endl;
}