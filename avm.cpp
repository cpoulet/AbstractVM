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
    Factory    F;
    const IOperand*   op1;
    const IOperand*   op2;
    const IOperand*   op3;
    op1 = F.createOperand(Int8, "126");
    std::cout << op1->toString() << std::endl;
    op2 = F.createOperand(Int16, "22767");
    std::cout << op2->toString() << std::endl;
    op3 = *op1 + *op2;
    std::cout << op3->toString() << std::endl;
    std::cout << "________________________" << std::endl;
    Parser      P;
    const IOperand* op4 = F.createOperand(Int32, "2");
    const IOperand* op5 = F.createOperand(Int32, "3");
    const IOperand* op6 = F.createOperand(Int32, "5");
    P.push(op4);
    P.push(op5);
    P.add();
    P.assert(op6);
    P.dump();
    P.pop();
    std::cout << "________________________" << std::endl;
    const IOperand* op7 = F.createOperand(Int32, "42");
    const IOperand* op8 = F.createOperand(Int32, "33");
    const IOperand* op9 = F.createOperand(Float, "44.55");
    const IOperand* op10 = F.createOperand(Double, "42.42");
    const IOperand* op11 = F.createOperand(Int32, "42");
    const IOperand* op12 = F.createOperand(Double, "42.42");
    P.push(op7);
    P.push(op8);
    P.add();
    P.push(op9);
    P.mul();
    P.push(op10);
    P.push(op11);
    P.dump();
    P.pop();
    P.assert(op12);
    return 0;
}
