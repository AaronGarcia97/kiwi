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
    // each child may have custom impl
    void display_datos();
};

class Input : public IO {
public:
    Input();
    void pedir_datos();
};

class Output : public IO {
public:
    Output();
    vector<Line> alter_lines();
};

#endif // IO_H
