#ifndef TOKEN_CLASS_HPP
# define TOKEN_CLASS_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Token {

public:

	Token();
	Token(std::string value, unsigned int type, unsigned int line);
	Token(Token const &);
	Token &	operator=(Token const &);
	virtual ~Token() {}

	std::string 	getValue() const;
	unsigned int 	getType() const;
	unsigned int	getLine() const;

    std::string     value;
    unsigned int    type;
    unsigned int    line;

};

std::ostream &	operator<<(std::ostream &, Token const &);

#endif
