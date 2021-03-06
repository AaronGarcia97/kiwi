#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Line {
private:
    string original_string_;
    vector<string> object_; // TODO: change name to this variable to a more descriptive one

public:
    Line(string);
    Line(string, vector<string>);
    static vector<string> convert_to_vector(string);
    static string convert_to_string(vector<string>, string);
    template <typename Out>
    static void split(const string&, char, Out);
    void display();

    // getters & setters
    string original_string() {return original_string_;}
    vector<string> object() {return object_;}
    void set_object(vector<string> object) {object_ = object;}
};

#endif // LINE_H
