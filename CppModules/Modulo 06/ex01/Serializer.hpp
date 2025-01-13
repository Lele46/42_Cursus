#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data
{
    int number;
    std::string str;
}               Data;

class Serializer
{
    public:
        Serializer();
        Serializer(Serializer const &);
        Serializer &operator=(Serializer const &);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif