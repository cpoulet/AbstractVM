#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

# include "IOperand.class.hpp"

# include <sstream>

template< typename T >
class Operand : public IOperand {

public:

    Operand(eOperandType type, T value) : _value(value), _type(type) {
        std::stringstream   ss;
        ss << this->_value;
        this->_str = ss.str();
        return;
    }

    Operand(Operand const & src) : _value(src.value), _type(src._type) {
        *this = src;
    }

    Operand &   operator=(Operand const & src) {
        if (this->_type != src.getType())
            throw "Nano La Fiotte";
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
/*
    IOperand const *    operator+( IOperand const & rhs ) const;
    IOperand const *    operator-( IOperand const & rhs ) const;
    IOperand const *    operator*( IOperand const & rhs ) const;
    IOperand const *    operator/( IOperand const & rhs ) const;
    IOperand const *    operator%( IOperand const & rhs ) const;

*/

private:

    Operand();

    T                   _value;
    const eOperandType  _type;
    std::string         _str;

};

#endif
