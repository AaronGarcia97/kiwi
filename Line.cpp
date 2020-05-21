#include "Line.h"

using namespace std;

// deprecated
Line::Line(string string_line) {
    cerr << "Constructing line." << endl;
    original_string_ = string_line;
}

// use this cosntructor, to ensure private fields are filled.
Line::Line(string string_line, vector<string> object) {
    cerr << "Constructing2 line." << endl;
    original_string_ = string_line;
    object_ = object;
}

// split implementation by Evan Teran, see:
// https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string 
template <typename Out>
void Line::split(const string &s, char delim, Out result) {
    istringstream iss(s);
    string item;
    while (getline(iss, item, delim)) {
        *result++ = item;
    }
}

vector<string> Line::convert_to_vector(string string_line) {
    cerr << "Converting string to vector." << endl;
    vector<string> v;
    char delim = ' ';
    Line::split(string_line, delim, back_inserter(v));
    return v;
}

string Line::convert_to_string(vector<string> v, string delim) {
    cerr << "Converting vector to string" << endl;
    string output = "";
    for(auto& word : v) {
        output += word;
        output += delim;
    }
    for(int i=0; i< delim.length(); i++)
        output.pop_back();
    return output;
}

void Line::display() {
    cerr << "Line displaying stuff." << endl;
    // TODO: impl different displays, original_string or vector display
    cerr << "string -----> " << original_string_ << endl;
    cerr << "vector -----> {" << flush;
    for (auto& word : object_) {
        cerr << word << ',' << flush;
    }
    cerr << '}' << endl;
}