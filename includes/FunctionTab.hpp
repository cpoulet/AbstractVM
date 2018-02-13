#ifndef FUNCTIONTAB_HPP
# define FUNCTIONTAB_HPP

# include <string>

typedef struct  s_instr_no_arg {
    std::string intr;
    void        (Parser::*f)();
}               t_instr_no_arg;

typedef struct  s_instr_with_arg {
    std::string intr;
    void        (Parser::*f)(const IOperand*);
}               t_instr_with_arg;

typedef struct      s_type {
    std::string     str;
    eOperandType    type;
}                   t_type;

#endif
