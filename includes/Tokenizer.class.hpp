#ifndef TOKENIZER_CLASS_HPP
# define TOKENIZER_CLASS_HPP

# include "Token.class.hpp"

# include <vector>

enum eTransition {
    REJECT = 0,
    MINUS,
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
	Tokenizer(Tokenizer const &);
	Tokenizer & operator=(Tokenizer const &);
	virtual ~Tokenizer();
    
    void                lexer(std::string input, unsigned int line);
    Token &             currentToken();
	Token &				nextToken();
	bool				next();
   
    class NoTokenException: public std::exception {
        public:
            virtual const char* what() const throw();
    };

private:
   
    int                 getTransition(char c) const;
    std::string         getType(int n) const;

    std::vector<Token>  _tokens;
    static int const    _stateTable[8][8];

};

#endif
