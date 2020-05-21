#ifndef IO_H
#define IO_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>

#include "Line.h"

using namespace std;

// TODO: clean lines, make them all lower case!
class IO {
protected:
    vector<Line> lines_;
    bool is_ascendente_;
public:
    IO();
    vector<Line> lines() {return lines_;}
    bool is_ascendente() {return is_ascendente_;}
    void set_is_ascendente(bool is_ascendente) {is_ascendente_ = is_ascendente;}
    void set_lines(vector<Line> lines) {lines_ = lines;}
    void add_line(Line);
    vector<vector <string> > vector_string_lines();
    // each child may have custom impl
    void display_datos();
};

class Input : public IO {
private:
    unordered_set<string> stop_words_;
public:
    Input();
    void pedir_datos();
    void filtrar_stop_words();
};

class Output : public IO {
private:
    vector<Line> modified_lines_;
public:
    Output();
    Output(vector<Line>);
    void alter_lines();
    vector<Line> modified_lines() {return modified_lines_;}
    void display_datos_debug(vector<Line>);
    void display_datos();
};

#endif // IO_H
