#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif /* SERIALIZER_HPP */