#include <iostream>
#include <string>

#include "Avm.hpp"
#include "Factory.class.hpp"
#include "Tokenizer.class.hpp"
#include "Parser.class.hpp"
#include "Operand.class.hpp"

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
    Tokenizer   T;
    std::vector<Token>  tokens;
    std::cout << "________________________" << std::endl;
	std::cout << "push int32(-42.42)\n;;" << std::endl;
    T.lexer("push int32(-42.42)\n;;", 1);
	while (1) {
		std::cout << T.currentToken();
		if (!T.next())
			break;
	}
    std::cout << "________________________" << std::endl;
    Factory Fact;
    const IOperand*   op;
    op = Fact.createOperand(Int8, "126");
    std::cout << op->toString() << std::endl;
    op = Fact.createOperand(Int16, "32767");
    std::cout << op->toString() << std::endl;
    delete op;
    return 0;
}
