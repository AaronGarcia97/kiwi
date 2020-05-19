#include "ProcessorContext.h"

using namespace std;

const vector<const string>
    ProcessorContext::available_strategies = {"SHIFT"};

ProcessorStrategyInterface::ProcessorStrategyInterface() {
    cout << "ProcessorStrategyInterface constructor." << endl;
}
 
ProcessorStrategy::ProcessorStrategy() {
    cout << "ProcessorStrategy constructor." << endl;
}

Output ProcessorStrategy::process(IO input) {
    cout << "ProcessorStrategy process function." << endl;
    return Output();
}

ShiftStrategy::ShiftStrategy() {
    cout << "ShiftStrategy constructor." << endl;
}

// TODO: utility methods, move them to their own class or namespace
void print(string msg) {
    cout << msg << endl;
}

void print_vector(vector<string>& v, string msg) {
    for(auto& s : v) {
        cout << s << ", ";
    }
    cout << endl;
}

void print_vector_of_vectors(vector< vector<string> >& vv, string msg) {
    print("Printing vector of vectors: ");
    print("size: " + to_string(vv.size()));
    cout << msg << ':' << endl;
    for(auto& v : vv) {
        print_vector(v, "");
    }
}
// ^^^ utility methods, move them to their own class or namespace ^^^

Output ShiftStrategy::process(IO input) {
    cout << "ShiftStrategy process function." << endl;
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
    for(auto& vector_string_line : vector_strings_output)
        lines_output.push_back(Line("", vector_string_line));

    // TODO: return what???
    return Output(lines_output);
}

ProcessorContext::ProcessorContext() {
    cout << "ProcessorContext constructor." << endl;
}

ProcessorContext::ProcessorContext(string) {
    cout << "ProcessorContext 2nd constructor." << endl;
}

Output ProcessorContext::process_lines() {
    cout << "ProcessorContext process_lines method." << endl;
    return Output();
}