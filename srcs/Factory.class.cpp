#include "Factory.class.hpp"

const IOperand* Factory::createOperand(eOperandType type, std::string const & value) const {
    FactoryFunc tab[] = {&Factory::createInt8, &Factory::createInt16, &Factory::createInt32, &Factory::createFloat, &Factory::createDouble};
    return (this->*tab[type])(value);
}

Factory::Factory() {
    return;
}

Factory::Factory(Factory const & src) {
    *this = src;
}

Factory &   Factory::operator=(Factory const & src) {
    (void)src;
    return *this;
}

Factory::~Factory() {
    return;
}

const IOperand* Factory::createInt8(std::string const & value) const {
    (void) value;
    std::cout << "Creating an Int8" << std::endl;
    return 0;
}

const IOperand* Factory::createInt16(std::string const & value) const {
    (void) value;
    std::cout << "Creating an Int16" << std::endl;
    return 0;
}

const IOperand* Factory::createInt32(std::string const & value) const {
    (void) value;
    std::cout << "Creating an Int32" << std::endl;
    return 0;
}

const IOperand* Factory::createFloat(std::string const & value) const {
    (void) value;
    std::cout << "Creating an Float" << std::endl;
    return 0;
}

const IOperand* Factory::createDouble(std::string const & value) const {
    (void) value;
    std::cout << "Creating an Double" << std::endl;
    return 0;
}

const char*     Factory::OverflowException::what() const throw() {
        return "Overflow";
}

const char*     Factory::UnderflowException::what() const throw() {
        return "Underflow";
}
