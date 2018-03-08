#ifndef PARSER_CLASS_HPP
# define PARSER_CLASS_HPP

# include "Factory.class.hpp"
# include "Lexer.class.hpp"
# include "IOperand.class.hpp"

# include <stack>
# include <map>

class Parser {

public:

    Parser();
    Parser(Parser const &);
    Parser &    operator=(Parser const &);
    virtual ~Parser();

    void    push();
    void    pop();
    void    dump();
    void    assert();
    void    add();
    void    sub();
    void    mul();
    void    div();
    void    mod();
    void    print();
    void    exit();

    void            read();
    void            read(std::string);
    void            parseLine(std::string, unsigned int);
    void            execute();
    void            instruction();
    const IOperand* getValue();

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
	std::map<std::string, Func>	_funcs;
	bool						_verbose;
    bool                        _exit;
    Lexer                       _lexer;
    Factory                     _factory;
};

#endif
