#ifndef PPROCESSOR_CONTEXT_H
#define PPROCESSOR_CONTEXT_H

#include <iostream>
#include <vector>
#include <string>

#include "IO.h"

using namespace std;

class ProcessorStrategyInterface {
protected:
    // TODO: verify if we should receive IO as parameter.
    virtual Output process(IO) = 0;
public:
    ProcessorStrategyInterface();
};

class ProcessorStrategy : public ProcessorStrategyInterface {
public:
    ProcessorStrategy();
    virtual Output process(IO);
};

// TODO: Verify if it shoud be extended with public or protected.
class ShiftStrategy : public ProcessorStrategy{
public:
    ShiftStrategy();
    Output process(IO);
};

class ProcessorContext {
private:
    ProcessorStrategy* processor_strategy_;

public:
    static const vector<const string> available_strategies;
    ProcessorContext();
    ProcessorContext(string);
    Output process_lines();

    //getters & setters
    ProcessorStrategy* processor_strategy() {return processor_strategy_;}
    void set_processor_strategy(ProcessorStrategy* processor_strategy)
        {processor_strategy_ = processor_strategy;}
};

#endif // PROCESSOR_CONTEXT_H
