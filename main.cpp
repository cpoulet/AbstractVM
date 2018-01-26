#include <iostream>
#include <string>

#include "Avm.hpp"
#include "Factory.class.hpp"
#include "cInt8.class.hpp"


int main() {
    Factory Fact;
    Fact.createOperand(Int8, "value");
    IOperand    *ch = new cInt8;
    std::cout << ch->toString() << std::endl;
    return 0;
}
