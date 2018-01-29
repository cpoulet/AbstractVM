#ifndef CINT8_CLASS_HPP
# define CINT8_CLASS_HPP

# include "IOperand.class.hpp"

class cInt8 : public IOperand {

public:

    cInt8();

    std::string const & toString() const;

    eOperandType        getType() const;
    int                 getPrecision() const;
/*
    IOperand const *    operator+( IOperand const & rhs ) const;
    IOperand const *    operator-( IOperand const & rhs ) const;
    IOperand const *    operator*( IOperand const & rhs ) const;
    IOperand const *    operator/( IOperand const & rhs ) const;
    IOperand const *    operator%( IOperand const & rhs ) const;

*/

private:

    std::string                 _str;
    static const eOperandType   _type;
    static const int            _precision;

};

#endif
