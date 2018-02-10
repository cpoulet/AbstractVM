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
    int         n;
    IOperand*   op;
    std::cout << "Creating an Int8" << std::endl;
    try {
        n = std::stoi(value);
        if (n > CHAR_MAX || n < CHAR_MIN)
            throw Factory::OverflowException();
        op = new Operand<int8_t>(Int8, n, this);
    } catch (const std::out_of_range & exc) {
        throw Factory::OverflowException();
    }
    return op;
}

const IOperand* Factory::createInt16(std::string const & value) const {
    int         n;
    IOperand*   op;
    std::cout << "Creating an Int16" << std::endl;
    try {
        n = std::stoi(value);
        if (n > SHRT_MAX || n < SHRT_MIN)
            throw Factory::OverflowException();
        op = new Operand<int16_t>(Int16, n, this);
    } catch (const std::out_of_range & exc) {
        throw Factory::OverflowException();
    }
    return op;
}

const IOperand* Factory::createInt32(std::string const & value) const {
    IOperand*   op;
    std::cout << "Creating an Int32" << std::endl;
    try {
        op = new Operand<int32_t>(Int32, std::stoi(value), this);
    } catch (const std::out_of_range & oor) {
        throw Factory::OverflowException();
    }
    return op;
}

const IOperand* Factory::createFloat(std::string const & value) const {
    IOperand*   op;
    std::cout << "Creating an Float" << std::endl;
    try {
        op = new Operand<float>(Float, std::stof(value), this);
    } catch (const std::out_of_range & exc) {
        throw Factory::OverflowException();
    } catch (const std::underflow_error & ue) {
        throw Factory::UnderflowException();
    }
    return op;
}

const IOperand* Factory::createDouble(std::string const & value) const {
    IOperand*   op;
    std::cout << "Creating an Double" << std::endl;
    try {
        op = new Operand<double>(Double, std::stod(value), this);
    } catch (const std::out_of_range & exc) {
        throw Factory::OverflowException();
    } catch (const std::underflow_error & ue) {
        throw Factory::UnderflowException();
    }
    return op;
}

const char*     Factory::OverflowException::what() const throw() {
        return "Overflow error";
}

const char*     Factory::UnderflowException::what() const throw() {
        return "Underflow error";
}
