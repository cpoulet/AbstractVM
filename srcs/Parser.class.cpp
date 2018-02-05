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
