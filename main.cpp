#include "Avm.hpp"
#include "Factory.class.hpp"
#include <iostream>
#include <string>

int main() {
    Factory Fact;
    Fact.createOperand(Int8, "value");
    return 0;
}
