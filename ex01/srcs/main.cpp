#include <iostream>
#include "Serialization.hpp"

int main()
{
    Data data;
    data.value = 42;
    data.name = "Exercise01";

    unsigned long raw = Serializer::serialize(&data);
    std::cout << "Serialized address: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &data)
    {
        std::cout << "Deserialization succeeded!" << std::endl;
        std::cout << "Data.value = " << ptr->value
                  << ", Data.name = " << ptr->name << std::endl;
    }
    else
        std::cout << "Error: pointers do not match." << std::endl;

    return 0;
}