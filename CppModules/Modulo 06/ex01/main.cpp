#include "Serializer.hpp"

int main() 
{
    Data data;
    data.number = 36;
    data.str = "Hello, World!";
    std::cout << "Number: " << data.number << "\nString: " << data.str << std::endl;

    std::cout << "\n--- Serialization ---" << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data (raw pointer as integer): " << raw << std::endl;

    std::cout << "\n--- Deserialization ---" << std::endl;
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Number: " << ptr->number << std::endl;
    std::cout << "String: " << ptr->str << std::endl;
    return 0;
}
