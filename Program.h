#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <vector>
#include <string>

#include "IO.h"
#include "ProcessorContext.h"

using namespace std;

class Program {
private:
    Input input_;
    Output output_;
    ProcessorContext processor_context_;

public:
    // api
    Program();
    void start();
    void process();
    void display();

    // getters & setters
    Input input() {return input_;}
    Output output() {return output_;}
    ProcessorContext proccessor_context() {return processor_context_;}
    void set_input(Input input) {input_ = input;}
    void set_output(Output output) {output_ = output;}
    void set_processor_context(ProcessorContext processor_context)
        {processor_context_ = processor_context;}
};

#endif // PROGRAM_H
