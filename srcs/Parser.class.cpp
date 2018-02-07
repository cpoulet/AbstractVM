#include "Parser.class.hpp"

Parser::Parser() {
    return;
}

Parser::Parser(Parser const & src) {
    *this = src;
}

Parser &    Parser::operator=(Parser const & src) {
    this->_stack = src._stack;
    return *this;
}

Parser::~Parser() {
    return;
}

void        Parser::Push(IOperand* op) {
    this->_stack.push(op);
}

void        Parser::Pop() {
    if (this->_stack.empty())
        throw Parser::EmptyStackException();
    else
        this->_stack.pop();
}

void        Parser::Dump() const {
    std::stack<IOperand*>   cpy = this->_stack;
    
    while (!cpy.empty()) {
        std::cout << cpy.top()->toString() << std::endl;
        cpy.pop();
    }
}

void        Parser::Assert(IOperand* op) const {
    if (this->_stack.empty())
        throw Parser::EmptyStackException();
    else if (op != this->_stack.top())
        throw Parser::AssertException();
}

void        Parser::Add() {
    if (this->_stack.size() < 2)
        throw Parser::EmptyStackException();
    else {
        IOperand*   v1 = this->_stack.top();
        this->_stack.pop();
        IOperand*   v2 = this->_stack.top();
        this->_stack.pop();
//        this->_stack.push(v2 + v1);
        (void)v1;
        (void)v2;
    }
}

void        Parser::Sub() {
    if (this->_stack.size() < 2)
        throw Parser::EmptyStackException();
    else {
        IOperand*   v1 = this->_stack.top();
        this->_stack.pop();
        IOperand*   v2 = this->_stack.top();
        this->_stack.pop();
//        this->_stack.push(v2 - v1);
        (void)v1;
        (void)v2;
    }
}

void        Parser::Mul() {
    if (this->_stack.size() < 2)
        throw Parser::EmptyStackException();
    else {
        IOperand*   v1 = this->_stack.top();
        this->_stack.pop();
        IOperand*   v2 = this->_stack.top();
        this->_stack.pop();
//        this->_stack.push(v2 * v1);
        (void)v1;
        (void)v2;
    }
}

void        Parser::Div() {
    if (this->_stack.size() < 2)
        throw Parser::EmptyStackException();
    else {
        IOperand*   v1 = this->_stack.top();
        this->_stack.pop();
        IOperand*   v2 = this->_stack.top();
        this->_stack.pop();
//        this->_stack.push(v2 / v1);
        (void)v1;
        (void)v2;
    }
}

void        Parser::Mod() {
    if (this->_stack.size() < 2)
        throw Parser::EmptyStackException();
    else {
        IOperand*   v1 = this->_stack.top();
        this->_stack.pop();
        IOperand*   v2 = this->_stack.top();
        this->_stack.pop();
//        this->_stack.push(v2 % v1);
        (void)v1;
        (void)v2;
    }
}

void        Parser::Print() {
    if (this->_stack.empty())
        throw Parser::EmptyStackException();
    else if (this->_stack.top()->getType() != Int8)
        throw Parser::AssertException();
    std::cout << "print" << std::endl;
}

const char* Parser::UnknownInstructionException::what() const throw() {
    return "Unknown Instruction";
}

const char* Parser::EmptyStackException::what() const throw() {
    return "Cannot pop from empty Stack";
}

const char* Parser::ZeroDivisionException::what() const throw() {
    return "Division by zero";
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
