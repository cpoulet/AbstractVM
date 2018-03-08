#ifndef AVM_HPP
# define AVM_HPP

# include <iostream>
# include <fstream>

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

class Parser;

typedef void (Parser::*Func)(void);

#endif
