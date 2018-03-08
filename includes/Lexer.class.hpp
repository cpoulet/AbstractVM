#ifndef LEXER_CLASS_HPP
# define LEXER_CLASS_HPP

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
    COMMENT,
    EXIT,
    SPACE
};


class Lexer {

public:

    Lexer();
	Lexer(Lexer const &);
	Lexer & operator=(Lexer const &);
	virtual ~Lexer();
    
    void                lexer(std::string input, unsigned int line);
    Token &             currentToken();
	Token &				nextToken();
	bool				next();
	bool				expectToken(unsigned int);
    bool                isExit() const;
    void                addSep(unsigned int line);
   
    class NoTokenException: public std::exception {
        public:
            virtual const char* what() const throw();
    };

private:
   
    int                 getTransition(char c) const;
    std::string         getType(int n) const;

    std::vector<Token>  _tokens;
    static int const    _stateTable[10][10];

};

#endif
