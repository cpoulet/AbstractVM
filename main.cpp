#include <iostream>
#include <string>

#include "Avm.hpp"
#include "Factory.class.hpp"
#include "cInt8.class.hpp"
#include "Tokenizer.class.hpp"

int main(int ac, char** av) {
    if (ac == 1)
        std::cout << "Execute on standart input" << std::endl;
    else if (ac > 1) {
        std::ifstream   ifs(av[1]);
        if (ifs)
            std::cout << "Execute " << av[1] << std::endl;
        else
            std::cerr << "Impossible to open file " << av[1] << std::endl;
    }
    Factory Fact;
    Fact.createOperand(Int8, "value");
    IOperand    *ch = new cInt8;
    std::cout << ch->toString() << std::endl;
    Tokenizer   T;
    std::vector<Token>  tokens;
    T.parseLine("push int32(42.42)", 1);
    return 0;
}
