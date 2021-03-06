#include "Token.class.hpp"

Token::Token() {
	return;
}

Token::Token(std::string value, unsigned int type, unsigned int line) : value(value), type(type), line(line) {
	return;
}

Token::Token(Token const & src) {
	*this = src;
}

Token &	Token::operator=(Token const & src) {
	this->value = src.value;
	this->type = src.type;
	this->line = src.line;
	return *this;
}

std::string		Token::getValue() const {
	return this->value;
}

unsigned int 	Token::getType() const {
	return this->type;
}

unsigned int	Token::getLine() const {
	return this->line;
}

std::ostream &	operator<<(std::ostream & o, Token const & src) {
	o << "Token : " << " Line " << std::setw(6) << std::left << src.getLine();
    o << std::setw(10) << std::left << src.getType() << src.getValue() << std::endl;
	return o;	
}
