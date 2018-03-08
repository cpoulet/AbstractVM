#ifndef FUNCTIONTAB_HPP
# define FUNCTIONTAB_HPP

# include <string>

typedef struct  s_instr {
    std::string str;
    void        (Parser::*f)();
}               t_instr;

typedef struct      s_type {
    std::string     str;
    eOperandType    type;
}                   t_type;

#endif
