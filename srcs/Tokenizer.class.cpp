#include "Tokenizer.class.hpp"

int const Tokenizer::_stateTable[8][8] = {
    {REJECT, MINUS, INTEGER, REAL, STRING, OPERATOR, UNKNOWN, SPACE},
    {MINUS, UNKNOWN, INTEGER, REAL, UNKNOWN, UNKNOWN, UNKNOWN, REJECT},
    {INTEGER, REJECT, INTEGER, REAL, REJECT, REJECT, REJECT, REJECT},
    {REAL, REJECT, REAL, UNKNOWN, REJECT, REJECT, REJECT, REJECT},
    {STRING, STRING, STRING, STRING, STRING, REJECT, REJECT, REJECT},
    {OPERATOR, REJECT, REJECT, REJECT, REJECT, REJECT, REJECT, REJECT},
    {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN, REJECT, UNKNOWN, REJECT},
    {SPACE, REJECT, REJECT, REJECT, REJECT, REJECT, REJECT, REJECT}};

Tokenizer::Tokenizer() {
    return;
}

Tokenizer::Tokenizer(Tokenizer const & src) {
	*this = src;
}

Tokenizer &	Tokenizer::operator=(Tokenizer const & src) {
	this->_tokens = src._tokens;
	return *this;
}

Tokenizer::~Tokenizer() {
	return;
}

const char* Tokenizer::NoTokenException::what() const throw() {
    return "There is no token anymore.";
}

Token &     Tokenizer::currentToken() {
    if (this->_tokens.size())
        return this->_tokens[0];
    else
        throw NoTokenException();
}

Token &     Tokenizer::nextToken() {
    if (this->_tokens.size() >= 2)
        return this->_tokens[1];
    else
        throw NoTokenException();
}

bool		Tokenizer::next() {
    if (this->_tokens.size())
		this->_tokens.erase(this->_tokens.begin());
    return this->_tokens.size() ? true : false;
}

int         Tokenizer::getTransition(char c) const {
    if (c == ' ' or c == '\n')
        return SPACE;
    if (c == '-')
        return MINUS;
    else if (std::isdigit(c))
        return INTEGER;
    else if (c == '.')
        return REAL;
    else if (std::isalpha(c))
        return STRING;
    else if (c == '(' || c == ')' || c == ';')
        return OPERATOR;
    else
        return UNKNOWN;
}

std::string         Tokenizer::getType(int n) const {
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
    else
        return "UNKNOWN";
}

void        Tokenizer::lexer(std::string input, unsigned int line) {
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
            }
            token.value = "";
        } else {
            token.value += current;
            ++i;
        }
        previousState = currentState;
    }
    if (currentState != SPACE && token.value != "") {
        token.type = this->getType(currentState);
        token.line = line;
        this->_tokens.push_back(token);
    }
}
