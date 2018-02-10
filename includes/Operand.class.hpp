#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

# include "IOperand.class.hpp"
# include "Factory.class.hpp"

# include <sstream>
# include <cmath>

class Factory;

template< typename T >
class Operand : public IOperand {

public:

    Operand(eOperandType type, T value, const Factory* factory) : _value(value), _type(type), _factory(factory) {
        std::stringstream   ss;
        ss << +this->_value;
        this->_str = ss.str();
        return;
    }

    Operand(Operand const & src) : _value(src.value), _type(src._type) {
        *this = src;
    }

    Operand &   operator=(Operand const & src) {
        if (this->_type != src.getType())
            throw "Nano La Fiotte"; //TODO
        this->_value = src._value;
        this->_str = src._str;
        return *this;
    }
    
    virtual ~Operand() {}

    std::string const & toString() const {
        return this->_str;
    }

    eOperandType        getType() const {
        return this->_type;
    }

    int                 getPrecision() const {
        return this->_type;
    }

    T                   getValue() const {
        return this->_value;
    }

    IOperand const *    operator+( IOperand const & rhs ) const {
        eOperandType        type;
        std::stringstream   ss;
        double              op1;
        double              op2;
        this->_Build(rhs, type, op1, op2);
        ss << (op1 + op2);
        return this->_factory->createOperand(type, ss.str());
    }

    IOperand const *    operator-( IOperand const & rhs ) const {
        eOperandType        type;
        std::stringstream   ss;
        double              op1;
        double              op2;
        this->_Build(rhs, type, op1, op2);
        ss << (op1 - op2);
        return this->_factory->createOperand(type, ss.str());
    }

    IOperand const *    operator*( IOperand const & rhs ) const {
        eOperandType        type;
        std::stringstream   ss;
        double              op1;
        double              op2;
        this->_Build(rhs, type, op1, op2);
        ss << (op1 * op2);
        return this->_factory->createOperand(type, ss.str());
    }

    IOperand const *    operator/( IOperand const & rhs ) const {
        eOperandType        type;
        std::stringstream   ss;
        double              op1;
        double              op2;
        this->_Build(rhs, type, op1, op2);
        if (op2 == 0)
            throw Operand::ZeroDivisionException();
        ss << (op1 / op2);
        return this->_factory->createOperand(type, ss.str());
    }

    IOperand const *    operator%( IOperand const & rhs ) const {
        eOperandType        type;
        std::stringstream   ss;
        double              op1;
        double              op2;
        this->_Build(rhs, type, op1, op2);
        if (op2 == 0)
            throw Operand::ZeroDivisionException();
        ss << std::fmod(op1, op2);
        return this->_factory->createOperand(type, ss.str());
    }

    class ZeroDivisionException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Division by zero";
        }
    };

private:

    Operand();

    T                   _value;
    const eOperandType  _type;
    std::string         _str;
    const Factory*      _factory;

    void                _Build(IOperand const & rhs, eOperandType & type, double & op1, double & op2) const {
        type = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();
        op1 = std::stod(this->toString());
        op2 = std::stod(rhs.toString());
    }
};

#endif
