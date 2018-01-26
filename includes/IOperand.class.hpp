#ifndef IOPERAND_CLASS_HPP
# define IOPERAND_CLASS_HPP

# include <string>

class IOperand {
    
public:
    
    virtual ~IOperand() {}

    virtual std::string const & toString() const = 0;
/*
    virtual eOperandType        getType() const = 0;
    virtual int                 getPrecision() const = 0;

    virtual IOperand const *    operator+( IOperand const & rhs ) const = 0;
    virtual IOperand const *    operator-( IOperand const & rhs ) const = 0;
    virtual IOperand const *    operator*( IOperand const & rhs ) const = 0;
    virtual IOperand const *    operator/( IOperand const & rhs ) const = 0;
    virtual IOperand const *    operator%( IOperand const & rhs ) const = 0;
*/
};

#endif