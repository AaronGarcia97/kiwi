#include "ProcessorContext.h"

using namespace std;

const vector<const string>
    ProcessorContext::available_strategies = {"SHIFT"};

ProcessorStrategy::ProcessorStrategy() {
    cout << "ProcessorStrategy constructor." << endl;
}

ProcessorContext::ProcessorContext() {
    cout << "ProcessorContext constructor." << endl;
}

ProcessorContext::ProcessorContext(string) {
    cout << "ProcessorContext 2nd constructor." << endl;
}

void ProcessorContext::process_lines() {
    cout << "ProcessorContext process_lines method." << endl;
}

ShiftStrategy::ShiftStrategy() {
    cout << "ShiftStrategy constructor." << endl;
}

void ShiftStrategy::process(IO input) {
    cout << "ShiftStrategy process function." << endl;
}