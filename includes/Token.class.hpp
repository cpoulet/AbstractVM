#ifndef TOKEN_CLASS_HPP
# define TOKEN_CLASS_HPP

# include <iostream>
# include <string>

struct Token {

    std::string     value;
    std::string     type;
    unsigned int    line;

};

#endif
