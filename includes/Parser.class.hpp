#ifndef PARSER_CLASS_HPP
# define PARSER_CLASS_HPP

# include "Token.class.hpp"

# include <vector>

class Parser {

public:

    class UnknownInstructionException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class OverflowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class UnderflowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class EmptyStackException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class ZeroDivisionException : public std::exception {
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
    
private:
   
};

#endif
