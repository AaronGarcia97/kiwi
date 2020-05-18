#ifndef IO_H
#define IO_H

#include <iostream>
#include <vector>
#include <string>

#include "Line.h"

using namespace std;

class IO {
protected:
    vector<Line> lines_;
public:
    IO();
    vector<Line> lines() {return lines_;}
    void set_lines(vector<Line> lines) {lines_ = lines;}
    void add_line(Line);
};

class Input : protected IO {
public:
    Input();
    void pedir_datos();
};

class Output : protected IO {
public:
    Output();
    vector<Line> alter_lines();
    void display_datos();
};

#endif // IO_H
