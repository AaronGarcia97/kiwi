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

void ProcessorStrategy::process(IO input) {
    cout << "ProcessorStrategy process function." << endl;
}

ShiftStrategy::ShiftStrategy() {
    cout << "ShiftStrategy constructor." << endl;
}

void ShiftStrategy::process(IO input) {
    cout << "ShiftStrategy process function." << endl;
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