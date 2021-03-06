#ifndef FACTORY_CLASS_HPP
# define FACTORY_CLASS_HPP

# include "Avm.hpp"
# include "Operand.class.hpp"
# include "IOperand.class.hpp"

# include <iostream>
# include <string>

class Factory {

public:
    
    Factory();
    Factory(Factory const &);
    Factory & operator=(Factory const &);
    virtual ~Factory();
    
    IOperand const  *createOperand(eOperandType type, std::string const & value) const;

    bool    verbose;

	class OverflowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class UnderflowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

private:

    IOperand const * createInt8(std::string const & value) const;
    IOperand const * createInt16(std::string const & value) const;
    IOperand const * createInt32(std::string const & value) const;
    IOperand const * createFloat(std::string const & value) const;
    IOperand const * createDouble(std::string const & value) const;

};

typedef IOperand const  *(Factory::*FactoryFunc) (std::string const & value) const;

#endif
