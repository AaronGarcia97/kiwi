#ifndef PPROCESSOR_CONTEXT_H
#define PPROCESSOR_CONTEXT_H

#include <iostream>
#include <vector>
#include <string>

#include "IO.h"

using namespace std;

class ProcessorStrategy {
protected:
    // TODO: verify if we should receive IO as parameter.
    virtual void process(IO) = 0;
public:
    ProcessorStrategy();
};

// TODO: Verify if it shoud be extended with public or protected.
class ShiftStrategy : public ProcessorStrategy{
protected:
    void process(IO);
public:
    ShiftStrategy();
};

class ProcessorContext {
private:
    ShiftStrategy processor_strategy_;

public:
    static const vector<const string> available_strategies;
    ProcessorContext();
    ProcessorContext(string);
    void process_lines();

    //getters & setters
    ShiftStrategy processor_strategy() {return processor_strategy_;}
    void set_processor_strategy(ShiftStrategy processor_strategy)
        {processor_strategy_ = processor_strategy;}
};

#endif // PROCESSOR_CONTEXT_H