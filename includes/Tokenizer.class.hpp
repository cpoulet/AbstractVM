#ifndef TOKENIZER_CLASS_HPP
# define TOKENIZER_CLASS_HPP

# include "Token.class.hpp"

# include <vector>

enum eTransition {
    REJECT = 0,
    INTEGER,
    REAL,
    STRING,
    OPERATOR,
    UNKNOWN,
    SPACE
};


class Tokenizer {

public:

    Tokenizer();
    
    void                parseLine(std::string input, unsigned int line);
    Token &             currentToken();
   
    class NoTokenException: public std::exception {
        public:
            virtual const char* what() const throw();
    };

private:
   
    int                 getTransition(char c) const;
    std::string         getType(int n) const;

    std::vector<Token>  _tokens;
    static int const    _stateTable[7][7];

};

#endif
