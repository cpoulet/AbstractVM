#include "Lexer.class.hpp"

int const Lexer::_stateTable[10][10] = {
    {REJECT, MINUS, INTEGER, REAL, STRING, OPERATOR, UNKNOWN, COMMENT, EXIT, SPACE},
    {MINUS, UNKNOWN, INTEGER, REAL, UNKNOWN, UNKNOWN, UNKNOWN, REJECT},
    {INTEGER, REJECT, INTEGER, REAL, REJECT, REJECT, REJECT, REJECT},
    {REAL, REJECT, REAL, UNKNOWN, REJECT, REJECT, REJECT, REJECT},
    {STRING, STRING, STRING, STRING, STRING, REJECT, REJECT, REJECT},
    {OPERATOR, REJECT, REJECT, REJECT, REJECT, REJECT, REJECT, REJECT},
    {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN, REJECT, UNKNOWN, REJECT},
    {COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT},
    {EXIT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, REJECT, COMMENT},
    {SPACE, REJECT, REJECT, REJECT, REJECT, REJECT, REJECT, REJECT}};

Lexer::Lexer() {
    return;
}

Lexer::Lexer(Lexer const & src) {
	*this = src;
}

Lexer &	Lexer::operator=(Lexer const & src) {
	this->_tokens = src._tokens;
	return *this;
}

Lexer::~Lexer() {
	return;
}

const char* Lexer::NoTokenException::what() const throw() {
    return "There is no token anymore.";
}

Token &     Lexer::currentToken() {
    if (this->_tokens.size())
        return this->_tokens[0];
    else
        throw NoTokenException();
}

Token &     Lexer::nextToken() {
    if (this->_tokens.size() >= 2)
        return this->_tokens[1];
    else
        throw NoTokenException();
}

bool		Lexer::next() {
    if (this->_tokens.size())
		this->_tokens.erase(this->_tokens.begin());
    return this->_tokens.size() ? true : false;
}

bool        Lexer::isExit() const {
    if (!this->_tokens.empty())
        return this->_tokens.back().type == "EXIT";
    else
        return false;
}

int         Lexer::getTransition(char c) const {
    if (c == ' ')
        return SPACE;
    if (c == '-')
        return MINUS;
    if (c == ';')
        return EXIT;
    else if (std::isdigit(c))
        return INTEGER;
    else if (c == '.')
        return REAL;
    else if (std::isalpha(c))
        return STRING;
    else if (c == '(' || c == ')')
        return OPERATOR;
    else
        return UNKNOWN;
}

std::string         Lexer::getType(int n) const {
    if (n == 1)
        return "MINUS";
    else if (n == 2)
        return "INTEGER";
    else if (n == 3)
        return "REAL";
    else if (n == 4)
        return "STRING";
    else if (n == 5)
        return "OPERATOR";
    else if (n == 7)
        return "COMMENT";
    else if (n == 8)
        return "EXIT";
    else
        return "UNKNOWN";
}

void        Lexer::addSep(unsigned int line) {
    Token   token("", "SEP", line);
    this->_tokens.push_back(token);
}

void        Lexer::lexer(std::string input, unsigned int line) {
    Token               token;
    char                current = 0;
    int                 col = REJECT;
    int                 currentState = REJECT;
    int                 previousState = REJECT;
    for (unsigned int i = 0; i < input.length();) {
        current = input[i];
        col = this->getTransition(current);
        currentState = this->_stateTable[currentState][col];
        if (currentState == REJECT) {
            if (previousState != SPACE) {
                token.type = this->getType(previousState);
                token.line = line;
                this->_tokens.push_back(token);
                if (previousState == EXIT)
                    break;
            }
            token.value = "";
        } else {
            token.value += current;
            ++i;
        }
        previousState = currentState;
    }
    if (currentState != SPACE && token.value != "" && previousState != EXIT) {
        token.type = this->getType(currentState);
        token.line = line;
        this->_tokens.push_back(token);
    }
}
