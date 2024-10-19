
#include "Serializer.hpp"

int main() 
{
    Data myData = {"hehehe", 0};
    Data* ptr = &myData;
    uintptr_t raw = Serializer::serialize(ptr);
    Data* deserializedPtr = Serializer::deserialize(raw);
    if (ptr == deserializedPtr) 
    {
        std::cout << "Serialization and deserialization worked correctly!" << std::endl;
        std::cout << "String: " << deserializedPtr->str << std::endl;
        std::cout << "I: " << deserializedPtr->i << std::endl;
    } 
    else
        std::cout << "Error: Pointers don't match." << std::endl;
    return 0;
}
