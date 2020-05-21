#include "ProcessorContext.h"

using namespace std;

const vector<const string>
    ProcessorContext::available_strategies = {"SHIFT"};

ProcessorStrategyInterface::ProcessorStrategyInterface() {
    cerr << "ProcessorStrategyInterface constructor." << endl;
}
 
ProcessorStrategy::ProcessorStrategy() {
    cerr << "ProcessorStrategy constructor." << endl;
}

Output ProcessorStrategy::process(IO input) {
    cerr << "ProcessorStrategy process function." << endl;
    return Output();
}

ShiftStrategy::ShiftStrategy() {
    cerr << "ShiftStrategy constructor." << endl;
}

// TODO: utility methods, move them to their own class or namespace
void print(string msg) {
    cerr << msg << endl;
}

void print_vector(vector<string>& v, string msg) {
    for(auto& s : v) {
        cerr << s << ", ";
    }
    cerr << endl;
}

void print_vector_of_vectors(vector< vector<string> >& vv, string msg) {
    print("Printing vector of vectors: ");
    print("size: " + to_string(vv.size()));
    cerr << msg << ':' << endl;
    for(auto& v : vv) {
        print_vector(v, "");
    }
}
// ^^^ utility methods, move them to their own class or namespace ^^^

Output ShiftStrategy::process(IO input) {
    cerr << "ShiftStrategy process function." << endl;
    vector<vector <string> > string_lines = input.vector_string_lines();
    vector<vector <string> > duplicated_string_lines(string_lines.size());
    int i = 0;

    // Explanation:
    // duplicated_string_lines will contain each vector duplicated.
    // e.g. {{1,2,3,1,2,3}, {4,5,6,4,5,6}}, etc
    // Simplifying shift strategy
    for(auto& vector_string_line : string_lines) {
        duplicated_string_lines[i].insert(
            duplicated_string_lines[i].end(),
            vector_string_line.begin(),
            vector_string_line.end());

        duplicated_string_lines[i].insert(
            duplicated_string_lines[i].end(),
            vector_string_line.begin(),
            vector_string_line.end());
        i++;
    }

    // print_vector_of_vectors(string_lines, "string_lines");
    // print_vector_of_vectors(duplicated_string_lines, "duplicated vector"); 

    // Explanation:
    // generate vector of strings output, iterating shift_cycle times over each
    // duplicated vector_string_line.
    int lines_count = string_lines.size();
    vector< vector<string> > vector_strings_output;
    // i => current line we are at
    for(int i = 0; i < lines_count; i++) {
        // shift_cyle => size of line
        int shift_cycle = string_lines[i].size();
        // j => shift iteration
        for(int j = 0; j < shift_cycle; j++) {
            vector<string> shifted_line;
            // k => position where this new shift is starting
            for(int k = j; k < shift_cycle + j; k++) {
                shifted_line.push_back(duplicated_string_lines[i][k]);
            }
            vector_strings_output.push_back(shifted_line);
        }        
    } 

    vector<Line> lines_output;
    // convert it to vector of lines
    for(auto& vector_string_line : vector_strings_output) {
        Line line = Line(
            Line::convert_to_string(vector_string_line, " "),
            vector_string_line);
        lines_output.push_back(line);
    }

    // TODO: return what???
    return Output(lines_output);
}

ProcessorContext::ProcessorContext() {
    cerr << "ProcessorContext constructor." << endl;
}

ProcessorContext::ProcessorContext(string) {
    cerr << "ProcessorContext 2nd constructor." << endl;
}

Output ProcessorContext::process_lines() {
    cerr << "ProcessorContext process_lines method." << endl;
    return Output();
}