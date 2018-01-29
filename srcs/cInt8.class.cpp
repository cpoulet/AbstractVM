#include "cInt8.class.hpp"

eOperandType const  cInt8::_type = Int8;
int const           cInt8::_precision = 8;

cInt8::cInt8() : _str("Int8") {
    return;
}

std::string const & cInt8::toString() const {
    return this->_str;
}

eOperandType        cInt8::getType() const {
    return this->_type;
}

int                 cInt8::getPrecision() const {
    return this->_precision;
}
