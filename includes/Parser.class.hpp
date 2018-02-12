#ifndef PARSER_CLASS_HPP
# define PARSER_CLASS_HPP

# include "Lexer.class.hpp"
# include "IOperand.class.hpp"

# include <stack>

class Parser {

public:

    Parser();
    Parser(Parser const &);
    Parser &    operator=(Parser const &);
    virtual ~Parser();

    void    push(const IOperand*);
    void    pop();
    void    dump() const;
    void    assert(const IOperand*) const;
    void    add();
    void    sub();
    void    mul();
    void    div();
    void    mod();
    void    print();

    void    read();
    void    read(std::string);
    void    parseLine(std::string, unsigned int);
    void    execute();

    class UnknownInstructionException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class EmptyStackException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class ExitMissingException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class AssertException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class NoValueException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class LexicalException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class SyntaxException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class WrongInputFileException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
private:

    std::stack<const IOperand*> _stack;
    bool                        _exit;
    Lexer                       _lexer;

};

#endif
