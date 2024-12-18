/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:00 by espinell          #+#    #+#             */
/*   Updated: 2024/10/31 10:37:00 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : _fixedvalue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedvalue = value << this->_fractionalbits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedvalue = roundf(value * (1 << this->_fractionalbits));
}
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedvalue = other.getRawBits();
    return *this;
}

//boolen operators
//-----------------------------------------------------
bool Fixed::operator>(const Fixed &other) const
{
    return this->_fixedvalue > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_fixedvalue < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_fixedvalue >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_fixedvalue <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_fixedvalue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_fixedvalue != other.getRawBits();
}
//-----------------------------------------------------
//math operators
//-----------------------------------------------------
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixedvalue + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixedvalue - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_fixedvalue * other.getRawBits()) >> this->_fractionalbits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_fixedvalue << this->_fractionalbits) / other.getRawBits());
    return result;
}
//-----------------------------------------------------
//increment and decrement operators
//-----------------------------------------------------
Fixed &Fixed::operator++()
{
    this->_fixedvalue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_fixedvalue++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->_fixedvalue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_fixedvalue--;
    return temp;
}
//-----------------------------------------------------
//min and max functions
//-----------------------------------------------------
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}
//-----------------------------------------------------

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->_fixedvalue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedvalue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixedvalue / (1 << this->_fractionalbits);
}

int Fixed::toInt(void) const
{
    return this->_fixedvalue >> this->_fractionalbits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}