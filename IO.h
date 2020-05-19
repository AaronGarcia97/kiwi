#ifndef IO_H
#define IO_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "Line.h"

using namespace std;

// TODO: clean lines, make them all lower case!
class IO {
protected:
    vector<Line> lines_;
public:
    IO();
    vector<Line> lines() {return lines_;}
    void set_lines(vector<Line> lines) {lines_ = lines;}
    void add_line(Line);
    vector<vector <string> > vector_string_lines();
    // each child may have custom impl
    void display_datos();
};

class Input : public IO {
public:
    Input();
    void pedir_datos();
};

class Output : public IO {
private:
    vector<Line> modified_lines_;
public:
    Output();
    Output(vector<Line>);
    void alter_lines();
    vector<Line> modified_lines() {return modified_lines_;}
    void display_datos();
};

#endif // IO_H
