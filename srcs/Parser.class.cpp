#include "Parser.class.hpp"

Parser::Parser() : _verbose(true), _exit(false) {
	this->_funcs["pop"] = &Parser::pop;
	this->_funcs["dump"] = &Parser::dump;
	this->_funcs["add"] = &Parser::add;
	this->_funcs["sub"] = &Parser::sub;
	this->_funcs["mul"] = &Parser::mul;
	this->_funcs["div"] = &Parser::div;
	this->_funcs["mod"] = &Parser::mod;
	this->_funcs["print"] = &Parser::print;
	this->_funcs["exit"] = &Parser::exit;
	this->_funcs["push"] = &Parser::push;
	this->_funcs["assert"] = &Parser::assert;
    return;
}

Parser::Parser(Parser const & src) {
    *this = src;
}

Parser &    Parser::operator=(Parser const & src) {
    this->_stack = src._stack;
    this->_exit = src._exit;
    return *this;
}

Parser::~Parser() {
    return;
}

void        Parser::read() {
    std::string     line;
    unsigned int    n = 0;
    while (!this->_exit && std::getline(std::cin, line)) {
        this->parseLine(line, ++n);
        this->_lexer.addSep(n);
    }
    this->execute();
}

void        Parser::read(std::string fname) {
    std::string     line;
    std::ifstream   in(fname);
    unsigned int    n = 0;
    if (!in)
        throw Parser::WrongInputFileException();
    while (std::getline(in, line)) {
        this->parseLine(line, ++n);
        this->_lexer.addSep(n);
    }
    this->execute();
}

void        Parser::parseLine(std::string line, unsigned int n) {
    this->_lexer.lexer(line, n);
    this->_exit = this->_lexer.isExit();
}

void        Parser::execute() {
    std::cout << "Executing : " << std::endl;
    while (1) {
        this->instruction();
        if (!this->_lexer.next())
            break;
    }
}

void        Parser::instruction() {
	if (this->_funcs.find(this->_lexer.currentToken().getValue()) != this->_funcs.end())
		(this->*(_funcs.at(this->_lexer.currentToken().getValue())))();
}

const IOperand* Parser::getValue() {
    const IOperand* op = this->_factory.createOperand(Int8, "32");
    return op;
}

void        Parser::push() {
	if (this->_verbose)
		std::cout << "Push" << std::endl;
    const IOperand*   op = this->getValue();
    this->_stack.push(op);
}

void        Parser::pop() {
	if (this->_verbose)
		std::cout << "Pop" << std::endl;
    if (this->_stack.empty())
        throw Parser::EmptyStackException();
    else
        this->_stack.pop();
}

void        Parser::dump() {
	if (this->_verbose)
		std::cout << "Dump" << std::endl;
    std::stack<const IOperand*>   cpy = this->_stack;
    while (!cpy.empty()) {
        std::cout << cpy.top()->toString() << std::endl;
        cpy.pop();
    }
}

void        Parser::assert() {
	if (this->_verbose)
		std::cout << "Assert" << std::endl;
    const IOperand*   op = this->getValue();
    if (this->_stack.empty())
        throw Parser::EmptyStackException();
    else if (op->toString() != this->_stack.top()->toString())
        throw Parser::AssertException();
}

void        Parser::add() {
	if (this->_verbose)
		std::cout << "Add" << std::endl;
    if (this->_stack.size() < 2)
        throw Parser::EmptyStackException();
    else {
        const IOperand* v1 = this->_stack.top();
        this->_stack.pop();
        const IOperand* v2 = this->_stack.top();
        this->_stack.pop();
        this->_stack.push(*v2 + *v1);
    }
}

void        Parser::sub() {
	if (this->_verbose)
		std::cout << "Sub" << std::endl;
    if (this->_stack.size() < 2)
        throw Parser::EmptyStackException();
    else {
        const IOperand* v1 = this->_stack.top();
        this->_stack.pop();
        const IOperand* v2 = this->_stack.top();
        this->_stack.pop();
        this->_stack.push(*v2 - *v1);
    }
}

void        Parser::mul() {
	if (this->_verbose)
		std::cout << "Mul" << std::endl;
    if (this->_stack.size() < 2)
        throw Parser::EmptyStackException();
    else {
        const IOperand* v1 = this->_stack.top();
        this->_stack.pop();
        const IOperand* v2 = this->_stack.top();
        this->_stack.pop();
        this->_stack.push(*v2 * *v1);
    }
}

void        Parser::div() {
	if (this->_verbose)
		std::cout << "Div" << std::endl;
    if (this->_stack.size() < 2)
        throw Parser::EmptyStackException();
    else {
        const IOperand* v1 = this->_stack.top();
        this->_stack.pop();
        const IOperand* v2 = this->_stack.top();
        this->_stack.pop();
        this->_stack.push(*v2 / *v1);
    }
}

void        Parser::mod() {
	if (this->_verbose)
		std::cout << "Mod" << std::endl;
    if (this->_stack.size() < 2)
        throw Parser::EmptyStackException();
    else {
        const IOperand* v1 = this->_stack.top();
        this->_stack.pop();
        const IOperand* v2 = this->_stack.top();
        this->_stack.pop();
        this->_stack.push(*v2 % *v1);
    }
}

void        Parser::print() {
	if (this->_verbose)
		std::cout << "Print" << std::endl;
    if (this->_stack.empty())
        throw Parser::EmptyStackException();
    else if (this->_stack.top()->getType() != Int8)
        throw Parser::AssertException();
}

void        Parser::exit() {
    std::cout << "Exit" << std::endl;
}

const char* Parser::UnknownInstructionException::what() const throw() {
    return "Unknown Instruction";
}

const char* Parser::EmptyStackException::what() const throw() {
    return "Cannot pop from empty Stack";
}

const char* Parser::ExitMissingException::what() const throw() {
    return "Need an exit instruction";
}

const char* Parser::AssertException::what() const throw() {
    return "Assertion failed";
}

const char* Parser::NoValueException::what() const throw() {
    return "Missing value";
}

const char* Parser::LexicalException::what() const throw() {
    return "Lexical problem";
}

const char* Parser::SyntaxException::what() const throw() {
    return "Syntax problem";
}

const char* Parser::WrongInputFileException::what() const throw() {
    return "Wrong input file";
}
